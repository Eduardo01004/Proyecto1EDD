var request = require('request');





 var requestData = 
 { "request": {
        "informacion": [
                {
                    "codigo": "ZRH",
                    "nombre": "DUS"
                    
                }
            
        
        ]
    }
}
var headersOpt = {  
    "content-type": "application/json; charset=utf-8",
};
        
  url = "http://localhost:9098/proyecto1/insertarDato/?informacion=codigo:aFAsd"


request(
        {
        method:'post',
        url:url,
        form: requestData, 
        headers: headersOpt,
        json: true,
    }, function (error, response, body) {  
        //Print the Response
        console.log(body);  
}); 
