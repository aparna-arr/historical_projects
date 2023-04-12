// Mozilla SDK API examples

/* 
 * Reloads current page every five minutes
 */

var tabs = require("sdk/tabs");
var contextMenu = require("sdk/context-menu");
var timer = require('sdk/timers');

var menuItem = contextMenu.Item({
	label: "Refresh every 5 min",
	contentScript: 'self.on("click", function() { self.postMessage(); });',
	onMessage: function() {
		var tab = tabs.activeTab;
		timer.setInterval(function() {tab.reload(); }, 300000);
	
	}
});


// https://developer.mozilla.org/en-US/Add-ons/SDK/Tutorials/Getting_started

/*
 * Adds a button to the firefox toolbar
 * on click, open Mozilla page in a seperate tab
 */ 

var buttons = require('sdk/ui/button/action');
var tabs = require("sdk/tabs");
var button = buttons.ActionButton({
	id: "mozilla-link",
	label: "Visit Mozilla",
	icon: {
		"16": "./icon-16.png",
	},
	onClick: handleClick
});

function handleClick(state) {
	tabs.open('https://mozilla.org');
}

// https://developer.mozilla.org/en-US/Add-ons/SDK/Tutorials/Modifying_Web_Pages_Based_on_URL

/*
 * Inserts html into web page if the url matches *.org
 */

var pageMod = require("sdk/page-mod");

pageMod.PageMod({
	include: "*.org"	,
 	contentScript: 'document.body.innerHTML = ' + 
			'"<h1>Page matches ruleset</h1>";'
});

// https://developer.mozilla.org/en-US/Add-ons/SDK/High-Level_APIs/page-mod
/*
 * Creates a button that, when clicked, highlights all div elements in current web page
 */
require("sdk/ui/button/action").ActionButton({
	id: "highlight-divs",
	label: "Highlight divs",
	icon: "./icon-16.png",
	onClick: function() {
		require("sdk/tabs").activeTab.attach({
			contentScript:
				'var divs = document.getElementsByTagName("div");' + 
				'for (var i = 0; i < divs.length; ++i) {' +
					'divs[i].setAttribute("style", "border: solid red 1px;");' +
				'}'
		});
	}
});


/* 
 * Floating Panel
 * It appears, but also autohides when you click elsewhere
 * Have not found solution 
 */

require("chrome");
var panel = require("sdk/panel").Panel({
	width: 180,
	height: 180,
	noautohide: true,
	contentURL: "https://en.wikipedia.org/w/index.php?title=Jetpack&useformat=mobile",
	contentScriptWhen: "start",
	contentScript: 'self.on("popuphiding", function(event) {' +
		'event.stopPropogation();' +
		'event.preventDefault();' +
		'});'
		
});

panel.show();

/*
var windows = require("sdk/windows").browserWindows;

windows.open({
	url: "http://www.example.com",
		onOpen: function (window) {

		}
});
*/

var {Toolbar} = require("sdk/ui/toolbar");

var button1 = ActionButton({
	id: "button1",
	label: "next",
	icon: "./icon-16.png"
});

var button2 = ActionButton({
	id: "button2",
	label: "next2",
	icon: "./icon-16.png"
});

var toolbar = Toolbar({
	title: "Test",
	items: [button1, button2]
});

toolbar.on("show", showing)
