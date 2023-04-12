//window.parent.postMessage(document.URL, "*");
/*
function getB() {
	window.parent.postMessage("hi", "*");
}

getB();
*/

var win = document.getElementById("window");
function parse (message) {
//	console.log(message.data);
///	var string = message.data.toString();
//	var first = string.split('?');
//	win.textContent = string;

	if (message.data.indexOf("http") > -1 || message.data.indexOf("about:blank") > -1)
	{
		if (message.data.indexOf("genome.ucsc.edu/cgi-bin/hgTrack") > -1)
		{
			win.textContent = "You are on UCSC!";
		}
		else
		{
			win.textContent = "You are NOT on UCSC!";
//			window.parent.postMessage("changeTab", "*");
		}
	} else {
		win.textContent = message.data;
	}
}

function redirect() {
	win.textContent = "Going to UCSC";
	window.parent.postMessage("changeTab", "*");
}

function getValue() {
	win.textContent = "Getting pos";
// can't get position from plugin ... need a tab content script
//	var string = $(".positionDisplay").text();

	window.parent.postMessage("getPos", "*");
//	win.textContent = string;
}

function stop() {
	win.textContent = "Stopping";
	window.parent.postMessage("stop", "*");
}

function getPos(pos) {
	win.textContent = pos;
}

window.addEventListener("message", parse, false);
window.addEventListener("pos", getPos, false);
