const worker = new Worker("worker.js");

worker.onmessage = function (event) {
    const users = event.data;

    if (!users || users.length === 0) {
        console.error("No users returned from the API.");
        return;
    }

    users.forEach(user => {
        console.log(
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        );
    });
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};