var panel = document.getElementById("panel");

self.port.on("show", function onShow() {
	panel.focus();
});
