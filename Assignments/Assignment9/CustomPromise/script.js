// This method should have fill implementation for below:

// executorFunction should be called with resolve and reject methods
// resolve()
// reject()
// then()
// catch()
// Promise chaining as below

function MyPromise(executorFunction) {
    let val;
    let state = "pending";

    let successCallbacks = [];
    let failureCallbacks = [];

    function resolve(value) {
        if (state != "pending") return;

        state = "fulfilled";
        val = value;
        successCallbacks.forEach((cb)=>cb(val));
    }

    function reject(error){
        if (state !== "pending") return;

        state = "rejected";
        val = error;
        failureCallbacks.forEach((cb)=>cb(error));

    }

    this.then = function(callback){
        if (state == "fulfilled") {
            val = callback(val);
        }
        else if (state == "pending") {
            successCallbacks.push(callback);
        }
        return this;
        
    }

    this.catch = function(callback){
        if (state == "rejected") {
            val = callback(val);
        }
        else if (state == "pending") {
            failureCallbacks.push(callback);
        }
        return this;
    }

    executorFunction(resolve,reject);   

    
}

new MyPromise((resolve,reject) => {
    resolve(5);
}).then(value => {
    return value * 2;
}).then(value => {
    return value * 5;
}).then(value => {
    console.log(value);
}).catch(()=>{
    console.log("value rejected")
});

// Output: 50

