//var pos = $(".positionDisplay").text();

var element = document.getElementById("positionDisplay");
var pos = element.textContent;
console.log("pos is " + pos);
self.port.emit("posMessage", pos);
