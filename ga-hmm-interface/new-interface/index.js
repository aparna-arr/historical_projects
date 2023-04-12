var self = require("sdk/self");

// a dummy function, to show how tests work.
// to see how to test this function, look at test/test-index.js
function dummy(text, callback) {
  callback(text);
}

exports.dummy = dummy;

var data = require("sdk/self").data;
/*
var my_panel = require("sdk/panel").Panel({
	contentURL: data.url("mypanel.html"),
	contentScript: data.url("my_panel_code.js")
});
*/
var tabs = require("sdk/tabs");
var { Frame } = require("sdk/ui/frame");
var { Toolbar } = require("sdk/ui/toolbar");
function runAlert(e) {
	alert(e.data);
}

var Positions = "";

var Files = require("sdk/io/file");
function getPos(e) {
	var worker = tabs.activeTab.attach({
		contentScriptFile: self.data.url("content_script.js")
	});

	worker.port.on("posMessage", function(message) {
		console.log("got message correctly: " + message);
		e.source.postMessage(message, "pos", e.origin);
/*
		var ReaderWriter = Files.open("~/ga-hmm-dump.txt", "w");
		if (!ReaderWriter.closed)
		{
			ReaderWriter.write(message);
			ReaderWriter.close();

		}
*/

		Positions += "<p>" + message + "</p>";
		console.log("Positions is " + Positions);
	});

}

function printPositions(tab) {
	tab.attach({
		contentScript: 'document.body.innerHTML = ' + ' " ' + Positions + ' " ; '
	});
}

function parseFrameMessage(e) {
	console.log("parsing message " + e.data);
	if (e.data == "changeTab")
	{
		tabs.activeTab.url = "http://genome.ucsc.edu/cgi-bin/hgTracks";
	}
	else if (e.data == "getPos")
	{
		getPos(e);
	}
	else if (e.data == "stop")
	{
		tabs.open({
			url:"about:blank",
			onActivate: printPositions
		});
	}	
}


// $(".positionDisplay").text()



var frame = new Frame({
	url: "./frame.html",
	onMessage: (e) => {
		console.log("Message: " + e.data);
		parseFrameMessage(e);
	}
});


tabs.open({
	url:"http://genome.ucsc.edu/cgi-bin/hgTracks",
	onActivate: runScript
});

function runScript(tab) {
//	frame.on("ready", testTab);
}

frame.on("ready", testTab);

function testTab(e) {
	/*
	console.log("active: " + tabs.activeTab.url);
	e.source.postMessage(tabs.activeTab.url, e.origin);
	var first = tabs.activeTab.url.split('?')[0];
	console.log("first: " + first);
	e.source.postMessage(first, e.origin);
*/
	tabs.on('activate', function() {
		console.log("active: " + tabs.activeTab.url);
//		var url = require("sdk/url").URL(tabs.activeTab.url);
//		var first = tabs.activeTab.url.split('?');

		first = tabs.activeTab.url.split('?')[0];
		console.log("first: " + first);
		e.source.postMessage(first, e.origin);
//		e.source.postMessage(first, e.origin);
	});

	tabs.on('load', function() {
		console.log("active: " + tabs.activeTab.url);
//		var url = require("sdk/url").URL(tabs.activeTab.url);
//		var first = tabs.activeTab.url.split('?');

		first = tabs.activeTab.url.split('?')[0];
		console.log("first: " + first);
		e.source.postMessage(first, e.origin);
//		e.source.postMessage(first, e.origin);
	});

}

var toolbar = Toolbar ({
	title:"TestFrame",
	items: [frame]
})




/*
tabs.open({
	url:"http://genome.ucsc.edu/cgi-bin/hgTracks",
	onReady: runScript
});
*/
//function runScript(tab) {
	/*
	tab.attach({
//		contentScript:"document.body.style.border = '5px solid red';"
		contentScript: showPanel
	});
	*/
//	my_panel.show();
//}

/*
function showPanel() {
	my_panel.show();
}

my_panel.on("show", function() {
	my_panel.port.emit("show");
});

let { getActiveView } = require("sdk/view/core");
getActiveView(my_panel).setAttribute("noautohide", true);
*/
