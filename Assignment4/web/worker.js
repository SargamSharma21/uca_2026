fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => {
        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }
        return response.json();
    })
    .then(users => {
        if (!users || users.length === 0) {
            postMessage([]);
        } else {
            postMessage(users);
        }
    })
    .catch(error => {
        console.error(error);
        postMessage([]);
    });