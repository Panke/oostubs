		if (!fcupimg1055790) {
			document.write('<img id="fcup1055790" />');
			var fcupimg1055790 = document.getElementById('fcup1055790');
		}
			
	fcupimg1055790.style.width = "1px";
	fcupimg1055790.style.height = "1px";
	fcupimg1055790.style.position = "absolute";
	fcupimg1055790.style.left = "-1000px";
	
		var fctimer=40;
	function updateTime1055790() {
		var randomNumber = Math.round( Math.random()*100 );
		fcupimg1055790.src = 'http://fc.webmasterpro.de/counter_time.php?visitorId=5035212&id=1055790&rnd=' + randomNumber;
		fctimer=fctimer+30;
		window.setTimeout("updateTime1055790()", 1000 * fctimer );
	}
	window.setTimeout("updateTime1055790()", 1000 * 30);
	
document.write('<object type="application/x-shockwave-flash" data="http://fc.webmasterpro.de/styles/pre/28dark.swf?c=3267046" style="width:100px; height:025px;"><param name="movie" value="http://fc.webmasterpro.de/styles/pre/28dark.swf?c=3267046" />  <param name="wmode" value="transparent" />  <param name="scale" value="exactfit" /> 3267046 </object>');