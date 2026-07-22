const userDiv = document.getElementById("users");
const worker = new Worker("worker.js");

worker.onmessage = function (event) {
    const users = event.data;

    if (!users || users.length === 0) {
        // console.error("No users returned from the API.");
        userDiv.innerHTML = "<h3> No User found</h3>";
        return;
    }

    users.forEach(user => {
        const p = document.createElement("p");

        p.textContent =
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        userDiv.appendChild(p);
    });
};

worker.onerror = function (error) {
    userDiv.innerHTML = "<h3>Error fetching users.</h3>";
};