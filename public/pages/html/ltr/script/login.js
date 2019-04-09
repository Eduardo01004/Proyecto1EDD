const button=document.getElementById('boton-enviar');
button.addEventListener('click',function(e){
	var nombre=document.getElementById("usuario").value;
	var contraseña=document.getElementById("contraseña").value;


	if(nombre=="gestor" && contraseña=="201612124"){


		toastr.success('Bienvenido usuario Gestor!', 'Login Exitoso');
			window.location.replace("index2.html");
	}

	else if(nombre=="admin" && contraseña=="201612124"){


			window.location.replace("index.html");
					toastr.success('Bienvenido usuario Administrador!', 'Login Exitoso');

	}


	else{
toastr.error('Error al iniciar sesion.', 'No permitido!');
	}
});
