# $NetBSD$

DISTNAME=       Gallery-2.21.3
PKGNAME=        js-${DISTNAME}
CATEGORIES=     www graphics
MASTER_SITES=   ${MASTER_SITE_GITHUB:=blueimp/}
GITHUB_PROJECT=	Gallery
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=     ast@NetBSD.org
HOMEPAGE=       https://github.com/blueimp/Gallery/
COMMENT=        JavaScript library to create image/video galleries
LICENSE=        mit

EXTRACT_USING=	bsdtar

NO_BUILD=            yes
NO_INSTALL_MANPAGES= yes

GALLERY_DIR=        share/${PKGBASE}
INSTALLATION_DIRS=  ${GALLERY_DIR}
INSTALLATION_DIRS+= ${GALLERY_DIR}/css
INSTALLATION_DIRS+= ${GALLERY_DIR}/img
INSTALLATION_DIRS+= ${GALLERY_DIR}/js
INSTALLATION_DIRS+= ${GALLERY_DIR}/js/vendor

WRKSRC= ${WRKDIR}/${DISTNAME}

GALLERY_FILES=  ${WRKSRC}/README.md
GALLERY_FILES+= ${WRKSRC}/LICENSE.txt
GALLERY_FILES+= ${WRKSRC}/index.html
GALLERY_FILES+= ${WRKSRC}/package.json

CSS_FILES=  ${WRKSRC}/css/blueimp-gallery-indicator.css
CSS_FILES+= ${WRKSRC}/css/blueimp-gallery-video.css
CSS_FILES+= ${WRKSRC}/css/blueimp-gallery.css
CSS_FILES+= ${WRKSRC}/css/blueimp-gallery.less
CSS_FILES+= ${WRKSRC}/css/blueimp-gallery.min.css
CSS_FILES+= ${WRKSRC}/css/blueimp-gallery.min.css.map
CSS_FILES+= ${WRKSRC}/css/demo.css

IMG_FILES=  ${WRKSRC}/img/error.png
IMG_FILES+= ${WRKSRC}/img/error.svg
IMG_FILES+= ${WRKSRC}/img/loading.gif
IMG_FILES+= ${WRKSRC}/img/play-pause.png
IMG_FILES+= ${WRKSRC}/img/play-pause.svg
IMG_FILES+= ${WRKSRC}/img/video-play.png
IMG_FILES+= ${WRKSRC}/img/video-play.svg

JS_FILES=  ${WRKSRC}/js/blueimp-gallery-fullscreen.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery-indicator.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery-video.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery-vimeo.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery-youtube.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery.min.js
JS_FILES+= ${WRKSRC}/js/blueimp-gallery.min.js.map
JS_FILES+= ${WRKSRC}/js/blueimp-helper.js
JS_FILES+= ${WRKSRC}/js/demo.js
JS_FILES+= ${WRKSRC}/js/jquery.blueimp-gallery.js
JS_FILES+= ${WRKSRC}/js/jquery.blueimp-gallery.min.js
JS_FILES+= ${WRKSRC}/js/jquery.blueimp-gallery.min.js.map

VENDOR_FILES= ${WRKSRC}/js/vendor/jquery.js

MY_DIR= ${DESTDIR}${PREFIX}/share/${PKGBASE}

do-install:
	for d in ${INSTALLATION_DIRS}; do ${MKDIR} -m 0755 ${PREFIX}/$${d}; done
	${INSTALL_DATA} -m 444 ${GALLERY_FILES} ${MY_DIR}
	${INSTALL_DATA} -m 444 ${CSS_FILES}     ${MY_DIR}/css
	${INSTALL_DATA} -m 444 ${IMG_FILES}     ${MY_DIR}/img
	${INSTALL_DATA} -m 444 ${JS_FILES}      ${MY_DIR}/js
	${INSTALL_DATA} -m 444 ${VENDOR_FILES}  ${MY_DIR}/js/vendor

.include "../../mk/bsd.pkg.mk"
