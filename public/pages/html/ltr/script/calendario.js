var globalA="";
var edifT3=0;
window.catedratico;
window.dia;

const host7 = '192.168.43.61:3000';

function cali(){
  $(function() {
  // initialize the external events
  // -----------------------------------------------------------------;
  $('#calendar-events .m-b-20').each(function() {

    // store data so the calendar knows to render an event upon drop
    $(this).data('event', {
      title: $.trim($(this).text()), // use the element's text as the event title
      stick: true // maintain when user navigates (see docs on the renderEvent method)
    });

    // make the event draggable using jQuery UI
    $(this).draggable({
      zIndex: 999,
      revert: true,      // will cause the event to go back to its
      revertDuration: 0,  //  original position after the drag
      start: null,
      end: null,
    });

  });

  $("#calendar").fullCalendar({
    selectable: true,
    droppable: true,
     editable: true,
     aspectRatio: 1.8,
     defaultView: "timelineDay",
    header: {
      left: "today prev,next",
      center: "title",
      right: "timelineDay,timelineWeek"
    },
    dayClick: function(date) {
         alert('clicked ' + date.format());
       },
       eventClick: function(eventObj) {
       if (eventObj.url) {
         alert(
           'Clicked ' + eventObj.title + '.\n' +
           'Will open ' + eventObj.url + ' in a new tab'
         );

         window.open(eventObj.url);

         return false; // prevents browser from following link in current tab.
       } else {
         alert('Clicked ' + eventObj.title);
       }
     },drop: function(date) {
             // retrieve the dropped element's stored Event Object
            var originalEventObject = $(this).data('eventObject');
            var $categoryClass = $(this).attr('name');
            // we need to copy it, so that multiple events don't have a reference to the same object
            var copiedEventObject = $.extend({}, originalEventObject);
            dia =obtenerdia(date._d.getDate(),date._d);
          if ($categoryClass)
           copiedEventObject['className'] = [$categoryClass];

            catedratico=copiedEventObject['className'];
           copiedEventObject.start  = new Date(date._d.getTime());
           copiedEventObject.end = new Date(date._d.getTime()+3000000);
            var h_i=calcTime(copiedEventObject.start);
            var h_f=calcTime(copiedEventObject.end);
            /*alert('Catedratico: ' + copiedEventObject['className']+ '.\n' +
                  'Dia: ' + dia + '.\n' +
                  'Inicio: ' + h_i + '.\n' +
                  'Finalizo: ' + h_f + '.');*/
           // Push the event into the array
           //arrayOfEvents.push(copiedEventObject);

            //addEvent(copiedEventObject); // Add the event to the db

            $('#calendar').fullCalendar('renderEvent', copiedEventObject, true);

            if ($('#drop-remove').is(':checked')) {
                $(this).remove();
            }

         // is the "remove after drop" checkbox checked?
         // if ($('#drop-remove').is(':checked')) {
         // if so, remove the element from the "Draggable Events" list
         // $(this).remove();
         //}

      },eventResize:function( event, jsEvent, ui, view ) {

                var curso=event.title;
                var hora_i=calcTime(new Date(event.start));
                var hora_f=calcTime(new Date(event.start+3000000));
                var separar= hora_i.split(':');
                var coorx=separar[0]+separar[1];
                var coory=event.resourceId;


                //alert(coory+"\n"+coorx+"\n"+curso+"\n"+catedratico+"\n"+dia+"\n"+hora_i+"\n"+hora_f);
              //  <!--alert("Event : "+ event.title+" StartTime : "+event.start+" End "+(event.start+3000000));-->
        },
        eventReceive: function(event, jsEvent, ui, view ){


                var curso=event.title;
                var hora_i=calcTime(new Date(event.start));
                var hora_f=calcTime(new Date(event.start+3000000));
                var separar= hora_i.split(':');
                var coorx=separar[0]+separar[1];
                var coory=event.resourceId;
                var edi="T-3";
                var salon="103";
                var capa=50;
               $.ajax({
                type: 'GET',
                contentType: 'application/json',
                url: 'http://'+host7+'/guardarunDatoMatriz?coorx='+coorx+'&coory='+coory+'&datohora='+hora_i+'&dia='+dia+'&edificio='+edi+'&datosalon='+salon+'&capacidad='+capa+'&datocurso='+curso+'&datocate='+catedratico,
                json: true,
                success: function(data) {
                  toastr.success('Ingresado a la matriz funciona :=)');


                }
            });

        },


        slotDuration: '00:10:00',
        /* If we want to split day time each 15minutes */
        defaultTimedEventDuration:'00:50:00',
        minTime: '07:00:00',
        maxTime: '21:00:00',

          resourceColumns:[
        {
          labelText: "Edificios",
          field: "otro"
        },

        {
          labelText: "Capacidad",
          field: "occupancy"
        }
      ],
      resourceGroupField:'edificio',
      resources:JSON.parse(globalA),
      events: [
      /*{ id: "a", edificio:'T-3' ,otro:102, occupancy: 40 },
      { id: "b", edificio: 'T-3',otro:104, occupancy: 40 },
      { id: "c", edificio: "T-5",otro:11, occupancy: 60 },
      { id: "d", edificio: "T-7", occupancy: 40 },
      { id: "e", edificio: "S-12", occupancy: 40 }*/
      ]

    });

  });
}
function msgbonito() {
    $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host7+'/conseguirEdificios',
    json: true,
    success:function(data){
      var agregar ='';
      var json=JSON.parse(data);
     for (var i = 0; i < json.result.length; i++) {
          var counter = json.result[i];



                if(i==(json.length-1)){

                  if (counter.edificio=="T-3") {

                     edifT3=parseInt(edifT3)+parseInt(counter.capacidad);


                     console.dir(edifT3);

                  }

          agregar +=' { "id": "'+counter.codigo+'", "total": " '+edifT3+'", "edificio": "'+counter.edificio+'", "otro":  "'+counter.datosalon+'", "occupancy":"'+counter.capacidad+'" }';

                }else{

                  if (counter.edificio=="T-3") {

                     edifT3=parseInt(edifT3)+parseInt(counter.capacidad);


                     console.dir(edifT3);

                  }
                  agregar +=' { "id": "'+counter.codigo+'", "total": " '+edifT3+'", "edificio": "'+counter.edificio+'", "otro":  "'+counter.datosalon+'", "occupancy":"'+counter.capacidad+'" },';
                }



        }
        agregar= agregar.substring(0,agregar.length-1);
        var lol='['+agregar+']';
        globalA=lol;
        console.dir(JSON.parse(lol));

      }

    });
}
function holaCursos(){
    // Now send a request to your Node program
    $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://'+host7+'/getcurso',
    json: true,
    success: function(data) {
        var json=JSON.parse(data);
        var jsonob=JSON.parse(json['result']);
        for (var i = 0; i < jsonob.length; i++) {
            var counter = jsonob[i];

          /*  var div=document.createElement('div');
                div.className='m-b-20';
                div.setAttribute('name',counter.codigo);
                div.setAttribute('data-class','bg-info');
                div.innerText=counter.curso;
            var Di=document.createElement('i');
                Di.className='fa fa-circle text-success m-r-10';

                div.appendChild(Di);

                var pito=document.getElementById("mostrando");
                pito.appendChild(div);*/

            $( "#mostrando" ).append('<div name=\"'+counter.codigo+'\" class=\"m-b-20\" data-class=\"bg-info\"><i class=\"fa fa-circle text-success m-r-10\"></i>'+counter.curso+'</div>');
           }
        }
    });
}

function llamarbebes(){
  holaCursos();
  msgbonito();
}

function calcTime(fecha) {
  utc = fecha.getTime() + (fecha.getTimezoneOffset() * 60000);
  nd = new Date(utc + (3600000 * 0));
  var result =  nd .getHours()+':'+ nd.getMinutes();
  return result
}

function  obtenerdia(d , fecha){

  var dias = ["domingo", "lunes", "martes", "miercoles", "jueves", "viernes", "sabado"];

  var mes = fecha.getMonth()+1; //obteniendo mes
  var dia = d;
  var ano = fecha.getFullYear(); //obteniendo año
  if(dia<10)
      dia='0'+dia; //agrega cero si el menor de 10
  if(mes<10)
      mes='0'+mes //agrega cero si el menor de 10
  var fec = mes+"/"+dia+"/"+ano;
  var day = new Date(fec).getDay();

  return dias[day];
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));

}
  async function AgregrarCursoModal(){
        toastr.success('Modificado con exito', 'Succes');
        var codigo=document.getElementById("codi").value;
        var curso=document.getElementById("curs").value;
        var catedratico=document.getElementById("cate").value;
        await sleep(500);
        location.reload();
        //alert(codigo);
       $.ajax({
        type: 'GET',
        contentType: 'application/json',
        url: 'http://'+host7+'/getcursos?codigo='+codigo+'&curso='+curso+'&catedratico='+catedratico,
        json: true,
        success: function(data) {

        }
      });
    }
