function heavyprocess(){
   
        for(let i = 0 ; i < 10000000000 ; i ++){

        }
        console.log("done");
        // ("done"); 
}
onmessage = (e) => {
        if (e.data === "start") {
                console.log("worker called")
            heavyprocess();
            postMessage("done");
        }
    };