
/**------------------ARBOL---------------------*/
const host1 = '192.168.43.61:3000';

/*------------MOSTRAR ARBOL EN LA TABLA---------*/
function hola(){
  // Now send a request to your Node program
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/conseguirTodo',
    json: true,
    success: function(data) {
      var json=JSON.parse(data);
      var jsonob=JSON.parse(json['result']);
      for (var i = 0; i < jsonob.length; i++) {
        var counter = jsonob[i];
        $( "#mostrando" ).append(


          '<tr> <td data-col=\"id\">'+counter.codigo+'</td>'+
          '<td data-col=\"nombre\">'+counter.nombre+'</td>'+
          '<td>'+
          '<input type=\"button\" data-col=\"elim\" class=\"botonMaestro btn btn-danger btn-sm\"  value=\"Eliminar\">'+
          '</td>'+
          '<td>'+
          '<input type=\"button\" data-col=\"modi\" class=\"btModificar\" value=\"Modificar\">'+
          '</td>'+
          '</tr>'

        );
          var el = document.getElementsByClassName('btModificar');
          if (el) {
            el[i].addEventListener("click", function(){
              document.querySelector('.bg-modal').style.display="flex";
            });

          }else {
            alert('no existe')
          }

        document.querySelector('.cerrar').addEventListener("click", function(){
            document.querySelector('.bg-modal').style.display="none";
          });
      }
    }
  });
}
var cod;
$('body').on('click','td[data-col]',function(){
  $('#tablamaestro').data('col',$(this).data('col'));
}).on('click','input.btModificar',function(ex){
  var nombre;
  cod=$(this).parent().siblings("td[data-col=id]").text();
  nombre=$(this).parent().siblings("td[data-col=nombre]").text();;
  $(document).ready(function(){
    document.getElementById('lbCod').innerText="Codigo: "+cod;
  })
  ex.preventDefault();

  })

 function modificarArbol(){
  toastr.success('Modificado con exito', 'Succes');
var name=document.getElementById("nuevoNombre").value;
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/modificarCatedratico?codigo='+cod+'&nombre='+name,
    json: true,
    success: function(data) {

    }
  });
}


/*-------------CARGA MASIVA DE ARCHIVOS DEL ARBOL-----------*/
function leerArchivo(){
  //alert("Archivo cargado");
  toastr.success('Archivo cargado con exito', 'El sitio dice');
  var file=document.getElementById('chooseFile').files[0];
  var reader=new FileReader();
  reader.onloadend = function(evt) {
    //console.log(this.result);
    var lines=this.result.split('\n');
    for(var i=0;i<lines.length;i++){
      var tipo=lines[i].split(',');
      $.ajax({

        type: 'GET',
        contentType: 'application/json',
        url: 'http://'+host1+'/guardarunDato?codigo='+tipo[0]+'&nombre='+tipo[1],
        json: true,
        success: function(data) {

        }
      });
    }
  };

  reader.readAsText(file);
}

/*---------ELIMINAR NODO DE CATEDRATICO------------*/


$('body').on('click','td[data-col]',function(){
  $('#tablamaestro').data('col',$(this).data('col'));
}).on('click','input.botonMaestro',function(e){

  var col,txt,nombre;
  col=$("#tablamaestro").data('col');
  txt=$(this).parent().siblings("td[data-col="+col+"]").text();

  e.preventDefault();
  $.ajax({

    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/delete?codigo='+txt,
    json: true,
    success: function(data) {

      location.reload();
      toastr.success('Eliminado con exito', 'Succes');
    }
  });

});




/*---------------LISTA CIRCULAR-----------------------*/
//--------------------------------------------MODIFICAR CURSOS--------------------------------------------
/*----MUESTRA CURSOS EN LA TABLA ---------*/
function MostrarCursos(){
  // Now send a request to your Node program
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/getcurso',
    json: true,
    success: function(data) {
      var json=JSON.parse(data);
      var jsonob=JSON.parse(json['result']);
      for (var i = 0; i < jsonob.length; i++) {
        var counter = jsonob[i];
        $( "#mostrando" ).append(
          //'<td data-col=\"nombre\"><input type=\"text\" class=\"form-control is-valid\" value=\"'+counter.nombre+'\"></td>'+
          '<tr> <td data-col=\"codigo\">'+counter.codigo+'</td>'+
          '<td data-col=\"curso\">'+counter.curso+'</td>'+
          '<td data-col=\"catedratico\">'+counter.catedratico+'</td>'+
          '<td>'+
          '<input type=\"button\" class=\"botoncurso  btn btn-danger btn-sm\"  value=\"Eliminar\">'+
          '</td>'+
          '<td>'+
          '<input type=\"button\" class=\"botoncursoModificar\" value=\"Modificar\">'+
          '</td>'+
          '</tr>');

          var el1 = document.getElementsByClassName('botoncursoModificar');
          if (el1) {
            el1[i].addEventListener("click", function(){
              document.querySelector('.bg-modal').style.display="flex";
            });

          }else {
            alert('no existe')
          }

        document.querySelector('.cerrar').addEventListener("click", function(){
            document.querySelector('.bg-modal').style.display="none";
          });
      }
    }
  });
}


  var cod1;
  var curso,catedratico;
$('body').on('click','td[data-col]',function(){
  $('#tablacursos').data('col',$(this).data('col'));
}).on('click','input.botoncursoModificar',function(ex){


  cod1=$(this).parent().siblings("td[data-col=codigo]").text();
  curso=$(this).parent().siblings("td[data-col=curso]").text();
  catedratico=$(this).parent().siblings("td[data-col=catedratico]").text();
  $(document).ready(function(){
    document.getElementById('lbCod').innerText="Codigo: "+cod1;
  })
  ex.preventDefault();
});

function modificarCurso(){
 toastr.success('Modificado con exito', 'Succes');
var name1=document.getElementById("nuevoNombreCurso").value;
$.ajax({
  type: 'GET',
  contentType: 'application/json',
  url: 'http://'+host1+'/updatecursos?codigo='+cod1+'&curso='+name1+'&catedratico='+catedratico,
  json: true,
  success: function(data) {

  }
});
}

/*-------------CARGA MASIVA DE CURSOS--------*/
function leerArchivo2(){
  //alert("Archivo cargado");
  toastr.success('Archivo cargado con exito', 'El sitio dice');

  var file1=document.getElementById('chooseFile2').files[0];
  var reader1=new FileReader();
  reader1.onloadend = function(evt) {
    var lines1=this.result.split('\n');
    for(var i=0;i<lines1.length;i++){
      var tipo1=lines1[i].split(',');


      $.ajax({
        type: 'GET',
        contentType: 'application/json',
        url: 'http://'+host1+'/getcursos?codigo='+tipo1[0]+'&curso='+tipo1[1]+'&catedratico='+tipo1[2],
        json: true,
        success: function(data) {

        }
      });
    }
  };

  reader1.readAsText(file1);
}


/*---------------------DELETE CURSOS--------------------*/
$('body').on('click','td[data-col]',function(){
  $('#tablacursos').data('col',$(this).data('col'));
}).on('click','input.botoncurso',function(e){

  var col1,txt1,nombre1;
  col1=$("#tablacursos").data('col');
  txt1=$(this).parent().siblings("td[data-col="+col1+"]").text();

  e.preventDefault();
  $.ajax({

    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/deletecurso?codigo='+txt1,
    json: true,
    success: function(data) {

      location.reload();
      toastr.success('Eliminado con exito', 'Succes');
    }
  });
});

/*--------------MATRIZ DISPERSA-----------------------*/

function imagen(){
  // Now send a request to your Node program
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/base64prueba',
    json: true,
    success: function(data) {
        $( "#mostrarImagen" ).append(
              "<div class=\"col-lg-3 col-md-6\">"+
                  "<div class=\"card\">"+
                      "<div class=\"el-card-item\">"+
          "<div class=\"el-card-avatar el-overlay-1\"> <img src=\" ../../imagenes/curso.jpg \" alt=\"user\" />" +
              "<div class=\"el-overlay\" >"+
        "<ul class=\"list-style-none el-info\">"+
"<li class=\"el-item\"><a class=\"btn default btn-outline image-popup-vertical-fit el-link\" href=\" ../../imagenes/curso.jpg \"><i class=\"mdi mdi-magnify-plus\"></i></a></li>"+
    "<li class=\"el-item\"><a class=\"btn default btn-outline el-link\" href=\"javascript:void(0);\"><i class=\"mdi mdi-link\"></i></a></li>"+
                  "</ul>"+
              "</div>"+
          "</div>"+
          "<div class=\"el-card-content\">"+
              "<h4 class=\"m-b-0\">Lista Circular</h4> <span class=\"text-muted\">Arbol de Catedraticos</span>"+
          "</div>"+
      "</div>"+
  "</div>"+
"</div>"
        );

    }


  });
}

function imagenCatedraticos(){
  // Now send a request to your Node program
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/base64Arbol',
    json: true,
    success: function(data) {
        $( "#mostrarImagen" ).append(
              "<div class=\"col-lg-3 col-md-6\">"+
                  "<div class=\"card\">"+
                      "<div class=\"el-card-item\">"+
          "<div class=\"el-card-avatar el-overlay-1\"> <img src=\" ../../imagenes/ArbolCatedraticos.jpg \" alt=\"user\" />" +
              "<div class=\"el-overlay\" >"+
                  "<ul class=\"list-style-none el-info\">"+
                      "<li class=\"el-item\"><a class=\"btn default btn-outline image-popup-vertical-fit el-link\" href=\" ../../imagenes/ArbolCatedraticos.jpg \"><i class=\"mdi mdi-magnify-plus\"></i></a></li>"+
                      "<li class=\"el-item\"><a class=\"btn default btn-outline el-link\" href=\"javascript:void(0);\"><i class=\"mdi mdi-link\"></i></a></li>"+
                  "</ul>"+
              "</div>"+
          "</div>"+
          "<div class=\"el-card-content\">"+
              "<h4 class=\"m-b-0\">Arbol</h4> <span class=\"text-muted\">Arbol de Catedraticos</span>"+
          "</div>"+
      "</div>"+
  "</div>"+
"</div>"
        );

    }


  });
}

function imagenMatriz(){
  // Now send a request to your Node program
  $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/base64Agenda',
    json: true,
    success: function(data) {
        $( "#mostrarImagen" ).append(
              "<div class=\"col-lg-3 col-md-6\">"+
                  "<div class=\"card\">"+
                      "<div class=\"el-card-item\">"+
          "<div class=\"el-card-avatar el-overlay-1\"> <img src=\" ../../imagenes/Agenda.jpg \" alt=\"user\" />" +
              "<div class=\"el-overlay\" >"+
                  "<ul class=\"list-style-none el-info\">"+
                      "<li class=\"el-item\"><a class=\"btn default btn-outline image-popup-vertical-fit el-link\" href=\" ../../imagenes/Agenda.jpg \"><i class=\"mdi mdi-magnify-plus\"></i></a></li>"+
                      "<li class=\"el-item\"><a class=\"btn default btn-outline el-link\" href=\"javascript:void(0);\"><i class=\"mdi mdi-link\"></i></a></li>"+
                  "</ul>"+
              "</div>"+
          "</div>"+
          "<div class=\"el-card-content\">"+
              "<h4 class=\"m-b-0\">Arbol</h4> <span class=\"text-muted\">Agenda</span>"+
          "</div>"+
      "</div>"+
  "</div>"+
"</div>"
        );

    }


  });
}




function imagenCate(){
  $.ajax({

    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/imagenarbol',
    json: true,
    success: function(data) {
      //location.reload();
      toastr.success('graficado con exito', 'Succes');
    }
  });


}


function imagencursos(){
  $.ajax({

    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/imagencurso',
    json: true,
    success: function(data) {
      //location.reload();
      toastr.success('graficado con exito', 'Succes');
    }
  });


}

function imagenAgendamatriz(){
  $.ajax({

    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/imagenAgenda',
    json: true,
    success: function(data) {
      //location.reload();
      toastr.success('graficado con exito', 'Succes');
    }
  });


}



function leerArchivoEdificio(){
    toastr.success('Archivo cargado con exito', 'El sitio dice');
    var file=document.getElementById('chooseFile3').files[0];
    var reader=new FileReader();
    reader.onloadend = function(evt) {
    console.log(this.result);
    var lines=this.result.split('\n');
    for(var i=0;i<lines.length;i++){
        var tipo=lines[i].split(',');
        var id=tipo[0].split('-');
        var cy= id[1]*100+tipo[1];
        var vacio="";
        var vac=0;
        $.ajax({
            type: 'GET',
            contentType:'application/json',

url: 'http://'+host1+'/guardarunDatoEdificio?codigo='+cy+'&edificio='+tipo[0]+'&datosalon='+tipo[1]+'&capacidad='+tipo[2],
            json: true,
            success: function(data) {
            }
        });
      }
    };

    reader.readAsText(file);
}



function holaEdificios(){
    // Now send a request to your Node program
    $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host1+'/conseguirEdificios',
    json: true,
    success: function(data) {
        var json=JSON.parse(data);
        console.dir(json.result);
        for (var i = 0; i < json.result.length; i++) {
            var counter = json.result[i];
            $( "#Medificios" ).append(
                    '<tr><td style=\"visibility: hidden;width : 5px;\" data-col=\"id\">'+counter.codigo+'</td>'+
                    '<td data-col=\"edificio\">'+counter.edificio+'</td>'+
                    '<td data-col=\"datosalon\">'+counter.datosalon+'</td>'+
                    '<td data-col=\"capacidad\">'+counter.capacidad+'</td>'+
                      '<td>'+
                    '<input type=\"button\" class=\"editarbtn mdi mdi-close btn btn-light btn-sm\" data-toggle=\"tooltip\" data-placement=\"top\" title=\"Modify\" value=\"✓\">'+
                    '<input type=\"button\" class=\"eliminarbtn mdi mdi-close btn btn-light btn-sm\" data-toggle=\"tooltip\" data-placement=\"top\" title=\"Delete\" value=\"x\">'+
                    '</td>'+
                    '</tr>');

                    var el = document.getElementsByClassName('editarbtn');
                  if (el) {
                    el[i].addEventListener("click", function(){
                      document.querySelector('.bg-modal').style.display="flex";
                    });

                  }else {
                    toastr.error('No existe','Modificar Edificio')
                  }

                document.querySelector('.cerrar').addEventListener("click", function(){
                    document.querySelector('.bg-modal').style.display="none";
                  });
           }
        }
    });
}

//---------------------Eliminar-----------------------------------------------------

$('body').on('click','td[data-col]',function(){
    $('#tb_edificios').data('col',$(this).data('col'));
}).on('click','input.eliminarbtn',function(e){
    toastr.success('Eliminado con exito','Edificio');
    var col,cod,nombre;
    col=$("#tb_edificios").data('col');
    cod=$(this).parent().siblings("td[data-col="+col+"]").text();
    e.preventDefault();
    $.ajax({
        type: 'GET',
        contentType: 'application/json',
        url: 'http://'+host1+'/deshacerEdificio?codigo='+cod,
        json: true,
        success: function(data) {
            location.reload();

        }
    });
});
//------------------------Modificar-----------------------------------------------------
var cod1;
var edifi;
$('body').on('click','td[data-col]',function(){
    $('#tb_edificios').data('col',$(this).data('col'));
}).on('click','input.editarbtn',function(ex){
  cod1=$(this).parent().siblings("td[data-col=id]").text();
  edifi=$(this).parent().siblings("td[data-col=edificio]").text();
  $(document).ready(function(){
    document.getElementById('lbCod').innerText="Codigo: "+cod1;
  });
  ex.preventDefault();
});


function modificarEdificio(){
    toastr.success('Modificado con exito','Edificio');
    var name1=document.getElementById("nuevoNombreEdificio").value;
    $.ajax({
        type: 'GET',
        contentType: 'application/json',
        url: 'http://'+host1+'/editarEdificio?codigo='+cod1+'&edificio='+name1,
        json: true,
        success: function(data) {
            location.reload();

        }
    });
  }
