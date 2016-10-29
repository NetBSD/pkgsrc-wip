$NetBSD$

Slideshow on/off: click (tap) on center image (or type 's' with keyboard)
Remove forward and back buttons so slideshow works better

Move all fgallery files into view subdirectory so we can symlink it on
webserver to /usr/pkg/share/fgallery/view in DocumentRoot hierarchies

--- view/index.js.orig	2016-04-25 19:57:44.000000000 +0000
+++ view/index.js
@@ -52,8 +52,6 @@ var elist;	// thumbnail list
 var fscr;	// thumbnail list scroll fx
 var econt;	// picture container
 var ebuff;	// picture buffer
-var eleft;	// go left
-var eright;	// go right
 var oimg;	// old image
 var eimg;	// new image
 var cthumb;	// current thumbnail
@@ -66,6 +64,7 @@ var idle;	// idle timer
 var clayout;	// current layout
 var csr;	// current scaling ratio
 var sdir;	// scrolling direction
+var slideshow;	// slideshow status
 
 function resize()
 {
@@ -100,7 +99,7 @@ function resize()
   {
     econt.setStyles(
     {
-      'width': epos.x,
+      'width': (slideshow == 'on'? msize.x: epos.x),
       'height': msize.y
     });
   }
@@ -109,7 +108,7 @@ function resize()
     econt.setStyles(
     {
       'width': msize.x,
-      'height': epos.y
+      'height': (slideshow == 'on'? msize.y: epos.y)
     });
   }
 
@@ -244,12 +243,12 @@ function resizeMainImg(img)
 {
   var contSize = econt.getSize();
   var listSize = elist.getSize();
-  var thumbWidth = (clayout == 'horizontal'? listSize.x: listSize.y);
+  var thumbWidth = (slideshow == 'on'? 0: clayout == 'horizontal'? listSize.x: listSize.y);
   var data = imgs.data[img.idx].img;
   var width = data[1][0];
   var height = data[1][1];
   var imgrt = width / height;
-  var pad = padding * 2;
+  var pad = (slideshow == 'on'? 0: padding * 2);
 
   if(imgrt > (contSize.x / contSize.y))
   {
@@ -425,8 +424,31 @@ function toggleCap()
 
   // update indicator
   var img = document.id('togglecap', ehdr);
-  img.src = 'cap-' + capst + '.png';
+  img.src = 'view/cap-' + capst + '.png';
   showHdr();
+
+  //resume slideshow (as click stopped it)
+  toggleSlideshow();
+}
+
+function toggleSlideshow()
+{
+  if(slideshow == 'on')
+  {
+    idle.removeEvent('idle', next);
+    showHdr();
+    idle.addEvent('idle', hideHdr);
+    elist.setStyle('display', 'block');
+    slideshow = 'off';
+  }
+  else
+  {
+    hideHdr();
+    idle.addEvent('idle', next);
+    elist.setStyle('display', 'none');
+    slideshow = 'on';
+  }
+  resize();
 }
 
 function setupHeader()
@@ -435,33 +457,33 @@ function setupHeader()
   if(imgs.index)
   {
     var el = new Element('a', { 'title': 'Back to index', 'href': imgs.index });
-    el.set('html', '<img src=\"back.png\"/>');
+    el.set('html', '<img src="view/back.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.data[eidx].file)
   {
     var file = imgs.data[eidx].file[0];
     var el = new Element('a', { 'title': 'Download image', 'href': file });
-    el.set('html', '<img src=\"eye.png\"/>');
+    el.set('html', '<img src="view/eye.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.download)
   {
     var el = new Element('a', { 'title': 'Download album', 'href': imgs.download });
-    el.set('html', '<img src=\"download.png\"/>');
+    el.set('html', '<img src="view/download.png"/>');
     ehdr.adopt(el);
   }
   if(imgs.captions)
   {
-    var el = new Element('a', { 'title': 'Toggle captions (shortcut: c)' });
+    var el = new Element('a', { 'title': 'Toggle captions' });
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
   ehdr.setStyle('display', (ehdr.children.length? 'block': 'none'));
 }
 
@@ -549,7 +571,8 @@ function onMainReady()
 
   tthr = resetTimeout(tthr);
   idle.start();
-  showHdr();
+  if(slideshow != 'on')
+    showHdr();
   centerThumb(d);
 
   // prefetch next image
@@ -563,7 +586,7 @@ function onMainReady()
 function showThrobber()
 {
   var img = new Element('img', { id: 'throbber' });
-  img.src = "throbber.gif";
+  img.src = "view/throbber.gif";
   ehdr.empty();
   img.inject(ehdr);
   ehdr.setStyle('display', 'block');
@@ -574,31 +597,19 @@ function showThrobber()
 function hideHdr()
 {
   if(idle.started)
+  {
     ehdr.tween('opacity', 0);
-}
-
-function hideNav()
-{
-  emain.addClass('no-cursor');
-  eleft.tween('opacity', 0);
-  eright.tween('opacity', 0);
+    emain.addClass('no-cursor');
+  }
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
@@ -722,16 +733,6 @@ function initGallery(data)
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
@@ -771,10 +772,9 @@ function initGallery(data)
 
   // events and navigation shortcuts
   elist.addEvent('scroll', onScroll);
-  eleft.addEvent('click', prev);
-  eright.addEvent('click', next);
   window.addEvent('resize', onResize);
   window.addEvent('hashchange', change);
+  econt.addEvent('click', toggleSlideshow);
 
   window.addEvent('keydown', function(ev)
   {
@@ -788,10 +788,6 @@ function initGallery(data)
       ev.stop();
       next();
     }
-    else if(ev.key == 'c')
-    {
-      toggleCap();
-    }
   });
 
   econt.addEvent('mousewheel', function(ev)
@@ -819,8 +815,7 @@ function initGallery(data)
     timeout: hidedelay,
     events: ['mousemove', 'mousedown', 'mousewheel']
   }).start();
-  idleTmp.addEvent('idle', hideNav);
-  idleTmp.addEvent('active', function() { showNav(); showHdr(); });
+  idleTmp.addEvent('active', showHdr);
 
   // general idle callback
   idle = new IdleTimer(window, { timeout: hidedelay }).start();
@@ -871,12 +866,12 @@ function init()
   }).get();
 
   // preload some resources
-  Asset.images(['throbber.gif',
-		'left.png', 'right.png',
-		'eye.png', 'download.png', 'back.png',
-		'cap-normal.png', 'cap-always.png', 'cap-never.png',
-		'cut-left.png', 'cut-right.png',
-		'cut-top.png', 'cut-mov.png']);
+  Asset.images(['view/throbber.gif',
+		'view/left.png', 'view/right.png',
+		'view/eye.png', 'view/download.png', 'view/back.png',
+		'view/cap-normal.png', 'view/cap-always.png', 'view/cap-never.png',
+		'view/cut-left.png', 'view/cut-right.png',
+		'view/cut-top.png', 'view/cut-mov.png']);
 }
 
 window.addEvent('domready', init);
