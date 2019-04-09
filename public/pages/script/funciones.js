function hola(){
    // Now send a request to your Node program
    $.ajax({
    type: 'GET',
    contentType: 'application/json',
    url: 'http://localhost:3000/conseguirTodo',
    success: function(data) {
    	var json=JSON.parse(data);
    	var jsonob=JSON.parse(json['result']);

    	for (var i = 0; i < jsonob.length; i++) {
    		var counter = jsonob[i];
    		console.log(counter.id);
    		$( "#mostrando" ).append('<div><label for="name">'+counter.id+'</label></div>');
		}
    }
});
}





