var express = require('express');
var app = express();
var htpp=require('http');
var fs = require('fs');
var Request = require("request");
const host = '192.168.43.61:9098';


app.set("view engine","jade");

app.use(express.static("public"));

app.get("/",function(solictud,respuesta){
  respuesta.redirect('/pages/html/ltr/authentication-login.html');

});

//---------------------------Arbol ABB------------------------------

/*-------------OBTENER ARBOL DE CATEDRATICOS++++++++++++-*/
app.get('/conseguirTodo', function (req, res) {
  Request.get("http://"+host+"/proyecto1/inOrden", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    res.json(body);
    //console.dir(JSON.parse(body));
  });
});

/*-----------------------INGRESAR DATOS AL ARBOL-----------*/
url = "http://"+host+"/proyecto1/insertarDato/informacion"

var headersOpt = {
  "content-type": "application/json; charset=utf-8",
};

app.get('/guardarunDato', function (req, res) {
  console.log(req.query.nombre);
  Request.post(url, {
    headers: headersOpt,
    json: {

      "informacion":
      {

        "codigo": "\""+req.query.codigo+"\"",
        "nombre": "\""+req.query.nombre+"\"",

      }

    }

  }, (error, res, body) => {
    if (error) {
      console.error(error)
      return
    }
    //console.log(`statusCode: ${res.statusCode}`)
    //console.log(body)
  })
  res.end();
});


/*--------------------ELIMINAR DATOS DEL ARBOL --------------------*/
urlA = "http://"+host+"/proyecto1/borrar/n"

var headersOptA = {
  "content-type": "application/json; charset=utf-8",
};
app.get('/delete', function (req, res) {
  console.log(req.query.nombre);
  Request.post(urlA, {
    headers: headersOptA,
    json: {

      "n":"\""+req.query.codigo+"\""
          }

          }, (error, res, body) => {
            if (error) {
              console.error(error)
              return
              }
            //  console.log(`statusCode: ${res.statusCode}`)
    //console.log(body)
  })
  res.end();
});


urlU = "http://"+host+"/proyecto1/modificarCatedratico/cod/nom"

var headersOptU = {
  "content-type": "application/json; charset=utf-8",
};
app.get('/modificarCatedratico', function (req, res) {
  console.log(req.query.nombre);
  Request.post(urlU, {
    headers: headersOptU,
    json: {

      "cod":"\""+req.query.codigo+"\"",
      "nom":"\""+req.query.nombre+"\""
          }

          }
          , (error, res, body) => {
            if (error) {
              console.error(error)
              return
              }
            //  console.log(`statusCode: ${res.statusCode}`)
    //console.log(body)
  })
  res.end();
});

/*--------------------FIN ARBOL ABB*------------------------------/

/*---------------------------LISTA CIRCULAR DE CURSOS------------------------*/

/*---------------OBTENER CURSOS------------------*/
app.get('/getcurso', function (req, res) {
  Request.get("http://"+host+"/proyecto1/MostrarCir", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    res.json(body);
  //  console.dir(JSON.parse(body));
  });
});


url1 = "http://"+host+"/proyecto1/InsertarCircular"

var headersOpt1 = {
  "content-type": "application/json; charset=utf-8",
};

/*---------------INGRESAR CURSOS --------------------*/
app.get('/getcursos', function (req, res) {
  console.log(req.query.curso);

  Request.post(url1, {
    headers: headersOpt1,
    json: {

      "curso":
      {
        "codigo":   "\""+req.query.codigo+"\"",
        "curso":    "\""+req.query.curso+"\"",
        "catedratico":"\""+req.query.catedratico+"\"",
      }

    }

  }, (error, res, body) => {
    if (error) {
      console.error(error)
      return
    }
    //console.log(`statusCode: ${res.statusCode}`)
    //console.log(body)
  })
  res.end();

});

/***-------------MODIFICAR CURSOS +++++++------------*/
url4 = "http://"+host+"/proyecto1/Update"

var headersOpt9 = {
  "content-type": "application/json; charset=utf-8",
};


app.get('/updatecursos', function (req, res) {
  console.log(req.query.nombre);

  Request.post(url4, {
    headers: headersOpt9,
    json:
    {
      "cod":"\""+req.query.codigo+"\"",
      "curso":
      {
        "codigo":"\""+req.query.codigo+"\"",
        "curso":  "\""+req.query.curso+"\"",
        "catedratico":"\""+req.query.catedratico+"\"",
      }

    }

  }, (error, res, body) => {
    if (error) {
      console.error(error)
      return
    }
    console.log(`statusCode: ${res.statusCode}`)
    console.log(body)
  })
  res.end();

});


/*--------------------ELIMINAR DATOS DEL ARBOL --------------------*/
urlB = "http://"+host+"/proyecto1/deletecurso/codigo"

var headersOptB = {
  "content-type": "application/json; charset=utf-8",
};
app.get('/deletecurso', function (req, res) {
  console.log(req.query.nombre);
  Request.post(urlB, {
    headers: headersOptB,
    json: {

      "codigo":"\""+req.query.codigo+"\""
          }

  }, (error, res, body) => {
          if (error) {
            console.error(error)
          return
        }
        //console.log(`statusCode: ${res.statusCode}`)
        //console.log(body)
      })
        res.end();
});

/*------------------------------FIN LISTA CIRCULAR DE CURSOS ----------------------------*/




/*----------CALENDARIO-----------------*/

app.get('/conseguirEdificios', function (req, res) {
  Request.get("http://"+host+"/proyecto1/Mostrar", (error, response, body) => {
      if(error) {
          return console.dir(error);
      }
      res.json(body);
      //console.dir(JSON.parse(body));
  });
});

var headersOptE = {
    "content-type": "application/json; charset=utf-8",
};

urlE = "http://"+host+"/proyecto1/InsertarListaDoble/edifi"


app.get('/guardarunDatoEdificio', function (req, res) {
    console.log(req.query.edificio);
    Request.post(urlE, {
    headers: headersOptE,
    json: {
              "edifi":
               {
                      "codigo": req.query.codigo,
                      "edificio": req.query.edificio,
                      "datosalon": +req.query.datosalon,
                      "capacidad": req.query.capacidad,

              }
    }
  }, (error, res, body) => {
      if (error) {
        console.error(error)
        return
      }
      console.log(`statusCode: ${res.statusCode}`)
      console.log(body)
})
  res.end();
});

var headersOptZ = {
    "content-type": "application/json; charset=utf-8",
};

urlW = "http://"+host+"/proyecto1/insertarMatriz/mat"

app.get('/guardarunDatoMatriz', function (req, res) {
    console.log(req.query.edificio);
    Request.post(urlW, {
    headers: headersOptZ,
    json: {
              "mat":
               {
                      "coorx": req.query.coorx,
                      "coory": req.query.coory,
                      "datohora": req.query.datohora,
                      "dia": req.query.dia,
                      "edificio": req.query.edificio,
                      "datosalon": +req.query.datosalon,
                      "capacidad": req.query.capacidad,
                      "datocurso": req.query.datocurso,
                      "datocate": req.query.datocate,
              }
    }
  }, (error, res, body) => {
      if (error) {
        console.error(error)
        return
      }
      console.log(`statusCode: ${res.statusCode}`)
      console.log(body)
})
  res.end();
});

var headersOptEM = {
    "content-type": "application/json; charset=utf-8",
};
urlEM = "http://"+host+"/proyecto1/modificarEdificio/cod/cur"

app.get('/editarEdificio', function (req, res) {
    console.log(req.query.nombre);
    Request.post(urlEM, {
    headers: headersOptEM,
    json: {
              "cod":req.query.codigo,
              "cur":req.query.edificio,

    }

  }, (error, res, body) => {
      if (error) {
        console.error(error)
        return
      }
      console.log(`statusCode: ${res.statusCode}`)
      console.log(body)
})
  res.end();
});

app.get('/deshacerEdificio', function (req, res) {
    console.log(req.query.curso);
    Request.post(urlEE, {
    headers: headersOptEE,
    json: {
              "cod":req.query.codigo,

    }

  }, (error, res, body) => {
      if (error) {
        console.error(error)
        return
      }
      console.log(`statusCode: ${res.statusCode}`)
      console.log(body)
})
  res.end();
});

var headersOptEE = {
    "content-type": "application/json; charset=utf-8",
};
urlEE = "http://"+host+"/proyecto1/borrarEdificios/cod"



/*----------BASE64 DE LA IMAGEN DE CURSOS Y ARBOL+++-------------*/
app.get('/base64prueba', function (req, res) {
  Request.get("http://"+host+"/proyecto1/getB64", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    var a=JSON.parse(body);
    var b=a['result'];
    var data="data:image/jpeg;base64,"+b;
    var imagen=decodeImagen(data);

    fs.writeFile('public/pages/imagenes/curso.jpg',imagen.data);


    res.end();
  });
});


app.get('/base64Arbol', function (req, res) {
  Request.get("http://"+host+"/proyecto1/getB64Arbol", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    var a=JSON.parse(body);
    var b=a['result'];
    var data="data:image/jpeg;base64,"+b;
    var imagen=decodeImagen(data);

    fs.writeFile('public/pages/imagenes/ArbolCatedraticos.jpg',imagen.data);


    res.end();
  });
});
app.get('/base64Agenda', function (req, res) {
  Request.get("http://"+host+"/proyecto1/getB64Agenda", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    var a=JSON.parse(body);
    var b=a['result'];
    var data="data:image/jpeg;base64,"+b;
    var imagen=decodeImagen(data);

    fs.writeFile('public/pages/imagenes/Agenda.jpg',imagen.data);


    res.end();
  });
});


function decodeImagen(data){
  var matches=data.match(/^data:([A-Za-z-+\/]+);base64,(.+)$/),response={};
  console.log(matches.length)
  response.type=matches[1];
  response.data=new Buffer(matches[2],'base64');
  return response;
}



/**------------------IMAGENES---------------*/

/*-------------OBTENER ARBOL DE CATEDRATICOS++++++++++++-*/
app.get('/imagenarbol', function (req, res) {
  Request.get("http://"+host+"/proyecto1/graficaBinario", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    res.json(body);
    //console.dir(JSON.parse(body));
  });
});

/*-------------OBTENER ARBOL DE CATEDRATICOS++++++++++++-*/
app.get('/imagencurso', function (req, res) {
  Request.get("http://"+host+"/proyecto1/graficarCursos", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    res.json(body);
    //console.dir(JSON.parse(body));
  });
});

/*-------------OBTENER ARBOL DE CATEDRATICOS++++++++++++-*/
app.get('/imagenAgenda', function (req, res) {
  Request.get("http://"+host+"/proyecto1/graficarAgenda", (error, response, body) => {
    if(error) {
      return console.dir(error);
    }
    res.json(body);
    //console.dir(JSON.parse(body));
  });
});
const port = 3000;
app.listen(3000,'192.168.43.61');
