# $NetBSD$

DISTNAME=       Gallery-2.29.0
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
INSTALLATION_DIRS+= ${GALLERY_DIR}/css/demo
INSTALLATION_DIRS+= ${GALLERY_DIR}/img
INSTALLATION_DIRS+= ${GALLERY_DIR}/js/demo
INSTALLATION_DIRS+= ${GALLERY_DIR}/js/vendor

WRKSRC= ${WRKDIR}/${DISTNAME}

GALLERY_FILES=  ${WRKSRC}/README.md
GALLERY_FILES+= ${WRKSRC}/LICENSE.txt
GALLERY_FILES+= ${WRKSRC}/index.html
GALLERY_FILES+= ${WRKSRC}/package.json

MY_DIR= ${DESTDIR}${PREFIX}/share/${PKGBASE}

do-install:
	for d in ${INSTALLATION_DIRS}; do ${MKDIR} -m 0755 ${DESTDIR}${PREFIX}/$${d}; done
	${INSTALL_DATA} -m 444 ${GALLERY_FILES} ${MY_DIR}
	${INSTALL_DATA} -m 444 ${WRKSRC}/css/*.* ${MY_DIR}/css
	${INSTALL_DATA} -m 444 ${WRKSRC}/css/demo/*.* ${MY_DIR}/css/demo
	${INSTALL_DATA} -m 444 ${WRKSRC}/img/*.* ${MY_DIR}/img
	${INSTALL_DATA} -m 444 ${WRKSRC}/js/*.* ${MY_DIR}/js
	${INSTALL_DATA} -m 444 ${WRKSRC}/js/demo/*.* ${MY_DIR}/js/demo
	${INSTALL_DATA} -m 444 ${WRKSRC}/js/vendor/*.* ${MY_DIR}/js/vendor

.include "../../mk/bsd.pkg.mk"
