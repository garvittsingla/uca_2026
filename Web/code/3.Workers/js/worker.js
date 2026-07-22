function heavyprocess(number){
        let sum = 0;
        for(let i = 0 ; i < number ; i ++){
                sum +=i;
        }
        console.log(sum);
        // ("done"); 
}
onmessage = (e) => {
        if (e.data) {
                console.log("worker called")
            heavyprocess(e.data);
            postMessage("done");
        }
    };