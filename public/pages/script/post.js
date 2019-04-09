var request = require("request")

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
        
  url = "http://localhost:9098/proyecto1/insertarDato/{informacion}"



ola(){



request({
    url: url,
    method: "POST",
    headers: {
        "content-type": "application/json",
        },
    json: requestData
//  body: JSON.stringify(requestData)
    },

     function (error, response, body) {
        if (!error && response.statusCode === 200) {
            console.log(body)
        }
        else {

            console.log("error: " + error)
            console.log("response.statusCode: " + response.statusCode)
            console.log("response.statusText: " + response.statusText)
        }
    })
}