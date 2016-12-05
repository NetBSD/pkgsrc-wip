$NetBSD$

Slideshow on/off: click (tap) on center image (or type 's' with keyboard)
Remove forward and back buttons so slideshow works better

Move all fgallery files into view subdirectory so we can symlink it on
webserver to /usr/pkg/share/fgallery/view in DocumentRoot hierarchies

--- view/index.js.orig	2016-04-25 19:57:44.000000000 +0000
+++ view/index.js
@@ -4,10 +4,13 @@
 "use strict";
 
 var datafile = 'data.json';
+
+// dimensions
 var padding = 22;
-var duration = 500;
-var thrdelay = 1500;
-var hidedelay = 3000;
+var duration = 500;      // for scrolling
+var thrdelay = 1500;     // throbber delay
+var hidedelay = 3000;    // header and caption hiding delay
+var slidedelay = 5000;   // slide show delay
 var prefetch = 1;
 var minupscale = 640 * 480;
 var thumbrt = 16/9 - 5/3;
@@ -15,6 +18,34 @@ var cutrt = 0.15;
 var capdelay = 5000;
 var rdwdelay = 500;
 
+// state variables
+var emain;      // main object
+var eback;      // background
+var enoise;     // additive noise
+var eflash;     // flashing object
+var ehdr;       // header
+var ecap;       // caption
+var capst;      // caption status
+var captm;      // caption timeout
+var elist;      // thumbnail list
+var fscr;       // thumbnail list scroll fx
+var econt;      // picture container
+var ebuff;      // picture buffer
+var oimg;       // old image
+var eimg;       // new image
+var cthumb;     // current thumbnail
+var mthumb;     // thumbnail measurement cache
+var eidx;       // current index
+var tthr;       // throbber timeout
+var imgs;       // image list
+var first;      // first image
+var idle;       // general idle timer
+var idleMouse;  // idle mouse timer
+var clayout;    // current layout
+var csr;        // current scaling ratio
+var sdir;       // scrolling direction
+var slideshow;  // slideshow status
+
 Element.Events.hashchange =
 {
   onAdd: function()
@@ -32,41 +63,13 @@ Element.Events.hashchange =
     };
 
     if("onhashchange" in window
-    && (!Browser.ie || Browser.version > 7))
+        && (!Browser.ie || Browser.version > 7))
       window.onhashchange = hashchange;
     else
       hashchange.periodical(50);
   }
 };
 
-// some state variables
-var emain;	// main object
-var eback;	// background
-var enoise;	// additive noise
-var eflash;	// flashing object
-var ehdr;	// header
-var ecap;	// caption
-var capst;      // caption status
-var captm;      // caption timeout
-var elist;	// thumbnail list
-var fscr;	// thumbnail list scroll fx
-var econt;	// picture container
-var ebuff;	// picture buffer
-var eleft;	// go left
-var eright;	// go right
-var oimg;	// old image
-var eimg;	// new image
-var cthumb;	// current thumbnail
-var mthumb;	// thumbnail measurement cache
-var eidx;	// current index
-var tthr;	// throbber timeout
-var imgs;	// image list
-var first;	// first image
-var idle;	// idle timer
-var clayout;	// current layout
-var csr;	// current scaling ratio
-var sdir;	// scrolling direction
-
 function resize()
 {
   // best layout
@@ -100,7 +103,7 @@ function resize()
   {
     econt.setStyles(
     {
-      'width': epos.x,
+      'width': (slideshow == 'on'? msize.x: epos.x),
       'height': msize.y
     });
   }
@@ -109,7 +112,7 @@ function resize()
     econt.setStyles(
     {
       'width': msize.x,
-      'height': epos.y
+      'height': (slideshow == 'on'? msize.y: epos.y)
     });
   }
 
@@ -119,6 +122,7 @@ function resize()
 
 function onResize()
 {
+  setSlideshowOff();
   resize();
   onScroll();
 }
@@ -131,9 +135,9 @@ function onLayoutChanged(layout, sr)
   imgs.data.each(function(x, i)
   {
     var crop = x.thumb[1];
-    var size = (x.thumb[2]? x.thumb[2]: crop);
-    var offset = (x.thumb[3]? x.thumb[3]: [0, 0]);
-    var center = (x.center? [x.center[0] / 1000, x.center[1] / 1000]: [0.5, 0.5]);
+    var size = (x.thumb[2]? x.thumb[2] : crop);
+    var offset = (x.thumb[3]? x.thumb[3] : [0, 0]);
+    var center = (x.center? [x.center[0]/1000, x.center[1]/1000] : [0.5, 0.5]);
 
     var maxw, maxh;
     if(layout == 'horizontal')
@@ -155,7 +159,8 @@ function onLayoutChanged(layout, sr)
     {
       'width': Math.round(maxw * sr),
       'height': Math.round(maxh * sr),
-      'background-size': Math.round(crop[0] * sr) + "px " + Math.round(crop[1] * sr) + "px"
+      'background-size':
+         Math.round(crop[0] * sr) + 'px ' + Math.round(crop[1] * sr) + 'px'
     });
 
     // center cropped thumbnail
@@ -169,7 +174,8 @@ function onLayoutChanged(layout, sr)
     cy = Math.round(crop[1] / 2 - cy + dy / 2);
     cy = Math.max(Math.min(0, cy), dy);
 
-    x.eimg.setStyle('background-position', Math.round(cx * sr) + 'px ' + Math.round(cy * sr) + 'px');
+    x.eimg.setStyle('background-position',
+      Math.round(cx * sr) + 'px ' + Math.round(cy * sr) + 'px');
 
     // border styles
     var classes = ['cut-left', 'cut-right', 'cut-top', 'cut-bottom'];
@@ -244,13 +250,17 @@ function resizeMainImg(img)
 {
   var contSize = econt.getSize();
   var listSize = elist.getSize();
-  var thumbWidth = (clayout == 'horizontal'? listSize.x: listSize.y);
   var data = imgs.data[img.idx].img;
   var width = data[1][0];
   var height = data[1][1];
   var imgrt = width / height;
-  var pad = padding * 2;
-
+  var thumbWidth = 0;
+  var pad = 0;
+  if(slideshow != 'on')
+  {
+    thumbWidth = clayout == 'horizontal'? listSize.x: listSize.y;
+    pad = padding * 2;
+  }
   if(imgrt > (contSize.x / contSize.y))
   {
     img.width = Math.max(thumbWidth + pad, contSize.x - pad);
@@ -333,7 +343,6 @@ function onScroll()
     beg = Math.max(0, beg - psize);
     end = Math.min(imgs.data.length, end + psize);
   }
-
   for(var i = beg; i != end; ++i)
   {
     if(!imgs.data[i].thumbLoaded)
@@ -388,17 +397,20 @@ function hideCap(nodelay)
 function showCap(nodelay)
 {
   if(capst == 'never') return;
+  var cap = imgs.data[ecap.eidx]['caption'];
+  if(!cap || (cap[0].length + cap[1].length == 0))
+  {
+    hideCap(true);
+    return;
+  }
   captm = resetTimeout(captm);
   ecap.get('tween').cancel();
-
   if(nodelay) ecap.fade('show');
   else ecap.tween('opacity', 1);
   ecap.setStyle('display', 'block');
-
   if(capst != 'always')
   {
     // calculate a decent reading time
-    var cap = imgs.data[ecap.eidx]['caption'];
     var words = cap[0].split(' ').length + cap[1].split(' ').length;
     var delay = Math.max(capdelay, rdwdelay * words);
     captm = hideCap.delay(delay);
@@ -408,7 +420,6 @@ function showCap(nodelay)
 function toggleCap()
 {
   if(!imgs.captions) return;
-
   // switch mode
   if(capst == 'normal')
     capst = 'never';
@@ -416,53 +427,83 @@ function toggleCap()
     capst = 'always';
   else
     capst = 'normal';
-
   // update visual state
   if(capst == 'never')
     hideCap(true);
   else if(ecap.eidx == eidx)
     showCap(true);
-
   // update indicator
   var img = document.id('togglecap', ehdr);
-  img.src = 'cap-' + capst + '.png';
+  img.src = 'view/cap-' + capst + '.png';
   showHdr();
 }
 
+function setSlideshowOff()
+{
+  if(slideshow == 'off') return;
+  idle.removeEvent('idle', next);
+  showHdr();
+  elist.setStyle('display', 'block');
+  slideshow = 'off';
+}
+
+function setSlideshowOn()
+{
+  if(slideshow == 'on') return;
+  idle.addEvent('idle', next);
+  hideHdr();
+  elist.setStyle('display', 'none');
+  slideshow = 'on';
+}
+
+function toggleSlideshow()
+{
+  if(slideshow == 'on')
+    setSlideshowOff();
+  else
+    setSlideshowOn();
+  resize();
+}
+
 function setupHeader()
 {
   ehdr.empty();
+  var el;
   if(imgs.index)
   {
-    var el = new Element('a', { 'title': 'Back to index', 'href': imgs.index });
-    el.set('html', '<img src=\"back.png\"/>');
+    el = new Element('a', { 'title': 'Back to index', 'href': imgs.index });
+    el.set('html', '<img src="view/back.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.data[eidx].file)
   {
     var file = imgs.data[eidx].file[0];
-    var el = new Element('a', { 'title': 'Download image', 'href': file });
-    el.set('html', '<img src=\"eye.png\"/>');
+    el = new Element('a', { 'title': 'Download image', 'href': file });
+    el.set('html', '<img src="view/eye.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.download)
   {
-    var el = new Element('a', { 'title': 'Download album', 'href': imgs.download });
-    el.set('html', '<img src=\"download.png\"/>');
+    el = new Element('a', { 'title': 'Download album', 'href': imgs.download });
+    el.set('html', '<img src="view/download.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.captions)
   {
-    var el = new Element('a', { 'title': 'Toggle captions (shortcut: c)' });
+    el = new Element('a', { 'title': 'Toggle captions' });
     el.setStyle('cursor', 'pointer');
     el.addEvent('click', toggleCap);
-    var img = new Element('img', { 'id': 'togglecap', 'src': 'cap-' + capst + '.png' });
+    var img = new Element('img', { 'id': 'togglecap', 'src': 'view/cap-' + capst + '.png' });
     img.inject(el);
     el.inject(ehdr);
   }
   if(imgs.data[eidx].date)
-    ehdr.adopt(new Element('span', { 'html': '<b>Date</b>: ' + imgs.data[eidx].date }));
+    ehdr.adopt(new Element('span', { 'title': 'EXIF timestamp', 'html': imgs.data[eidx].date }));
+  el = new Element('a', { 'title': 'Overview', 'href': 'view/overview.html' });
+  el.set('html', '<img src="view/overview.png"/>');
+  ehdr.adopt(el);
   ehdr.setStyle('display', (ehdr.children.length? 'block': 'none'));
+  ehdr.removeEvent('click', toggleSlideshow);
 }
 
 function onMainReady()
@@ -513,11 +554,11 @@ function onMainReady()
     {
       var diff = umod(eidx - oimg.idx, imgs.data.length);
       if(diff == 1)
-	sdir = 1;
+        sdir = 1;
       else if(diff == imgs.data.length - 1)
-	sdir = -1;
+        sdir = -1;
       else
-	sdir = 0;
+        sdir = 0;
     }
 
     // fade old image
@@ -544,26 +585,30 @@ function onMainReady()
   fx.start('opacity', 1);
 
   var rp = Math.floor(Math.random() * 100);
-  eback.src = imgs.data[eidx].blur;
-  enoise.setStyle('background-position', rp + 'px ' + rp + 'px');
+  eback.src = '';
+  if (imgs.data[eidx].blur)
+  {
+    eback.src = imgs.data[eidx].blur;
+    enoise.setStyle('background-position', rp + 'px ' + rp + 'px');
+  }
 
   tthr = resetTimeout(tthr);
   idle.start();
-  showHdr();
+  if(slideshow != 'on') showHdr();
   centerThumb(d);
 
   // prefetch next image
   if(prefetch && sdir != 0)
   {
     var data = imgs.data[umod(eidx + sdir, imgs.data.length)];
-    Asset.images([data.img[0], data.blur]);
+    Asset.images([data.img[0], data.blur? data.blur :[]]);
   }
 }
 
 function showThrobber()
 {
   var img = new Element('img', { id: 'throbber' });
-  img.src = "throbber.gif";
+  img.src = "view/throbber.gif";
   ehdr.empty();
   img.inject(ehdr);
   ehdr.setStyle('display', 'block');
@@ -573,32 +618,17 @@ function showThrobber()
 
 function hideHdr()
 {
-  if(idle.started)
-    ehdr.tween('opacity', 0);
-}
-
-function hideNav()
-{
+  ehdr.tween('opacity', 0);
   emain.addClass('no-cursor');
-  eleft.tween('opacity', 0);
-  eright.tween('opacity', 0);
 }
 
 function showHdr()
 {
+  emain.removeClass('no-cursor');
   ehdr.get('tween').cancel();
   ehdr.fade('show');
 }
 
-function showNav()
-{
-  emain.removeClass('no-cursor');
-  eleft.get('tween').cancel();
-  eleft.fade('show');
-  eright.get('tween').cancel();
-  eright.fade('show');
-}
-
 function flash()
 {
   eflash.setStyle('display', 'block');
@@ -637,7 +667,7 @@ function load(i)
   if(i == eidx) return;
 
   var data = imgs.data[i];
-  var assets = Asset.images([data.img[0], data.blur],
+  var assets = Asset.images([data.img[0], data.blur? data.blur: []],
   {
     onComplete: function() { if(i == eidx) onMainReady(); }
   });
@@ -722,16 +752,6 @@ function initGallery(data)
   ecap = new Element('div', { id: 'caption' });
   ecap.inject(econt);
 
-  eleft = new Element('a', { id: 'left' });
-  eleft.adopt((new Element('div')).adopt(new Element('img', { 'src': 'left.png' })));
-  eleft.set('tween', { link: 'ignore' })
-  eleft.inject(econt);
-
-  eright = new Element('a', { id: 'right' });
-  eright.adopt((new Element('div')).adopt(new Element('img', { 'src': 'right.png' })));
-  eright.set('tween', { link: 'ignore' })
-  eright.inject(econt);
-
   ehdr = new Element('div', { id: 'header' });
   ehdr.set('tween', { link: 'ignore' })
   ehdr.inject(econt);
@@ -771,10 +791,9 @@ function initGallery(data)
 
   // events and navigation shortcuts
   elist.addEvent('scroll', onScroll);
-  eleft.addEvent('click', prev);
-  eright.addEvent('click', next);
   window.addEvent('resize', onResize);
   window.addEvent('hashchange', change);
+  econt.addEvent('click', toggleSlideshow);
 
   window.addEvent('keydown', function(ev)
   {
@@ -788,10 +807,6 @@ function initGallery(data)
       ev.stop();
       next();
     }
-    else if(ev.key == 'c')
-    {
-      toggleCap();
-    }
   });
 
   econt.addEvent('mousewheel', function(ev)
@@ -815,16 +830,21 @@ function initGallery(data)
   });
 
   // setup an idle callback for mouse movement only
-  var idleTmp = new IdleTimer(window, {
+  idleMouse = new IdleTimer(window, {
     timeout: hidedelay,
     events: ['mousemove', 'mousedown', 'mousewheel']
   }).start();
-  idleTmp.addEvent('idle', hideNav);
-  idleTmp.addEvent('active', function() { showNav(); showHdr(); });
+  idleMouse.addEvent('active', showHdr);
+  idleMouse.addEvent('idle', hideHdr);
 
   // general idle callback
-  idle = new IdleTimer(window, { timeout: hidedelay }).start();
-  idle.addEvent('idle', hideHdr);
+  idle = new IdleTimer(window, { timeout: slidedelay }).start();
+
+  // start slide show immediately if specified in data.json
+  if(imgs.startslideshow == 'yes')
+    setSlideshowOn();
+  else
+    setSlideshowOff();
 
   // prepare first image
   sdir = 1;
@@ -834,7 +854,10 @@ function initGallery(data)
   loadThumb(first);
   centerThumb(0);
 
+  // set visibility
   emain.setStyle('visibility', 'visible');
+  if(slideshow == 'on')
+    elist.setStyle('display', 'none');
 }
 
 function initFailure()
@@ -860,7 +883,7 @@ function init()
     onRequest: function()
     {
       if(this.xhr.overrideMimeType)
-	this.xhr.overrideMimeType('application/json');
+        this.xhr.overrideMimeType('application/json');
     },
     isSuccess: function()
     {
@@ -871,12 +894,12 @@ function init()
   }).get();
 
   // preload some resources
-  Asset.images(['throbber.gif',
-		'left.png', 'right.png',
-		'eye.png', 'download.png', 'back.png',
-		'cap-normal.png', 'cap-always.png', 'cap-never.png',
-		'cut-left.png', 'cut-right.png',
-		'cut-top.png', 'cut-mov.png']);
+  Asset.images([
+    'view/throbber.gif', 'view/overview.png', 'view/eye.png',
+    'view/download.png', 'view/back.png', 'view/cap-normal.png',
+    'view/cap-always.png', 'view/cap-never.png', 'view/cut-left.png',
+    'view/cut-right.png', 'view/cut-top.png', 'view/cut-mov.png'
+   ]);
 }
 
 window.addEvent('domready', init);
