# $NetBSD: Makefile,v 1.4 2007/05/24 18:50:22 hoka_adam Exp $
#

DISTNAME=	slim-1.2.6
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/slim/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://slim.berlios.de/
COMMENT=	SLiM is a Desktop-independent graphical login manager for X11

USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/slim.conf ${PKG_SYSCONFDIR}/slim.conf

RCD_SCRIPTS+=	slim

CFLAGS+=	-I. -I${BUILDLINK_DIR}/include -I${BUILDLINK_DIR}/freetype2 \
		-I${BUILDLINK_DIR}/freetype2/config -I${BUILDLINK_DIR}/include/libpng12 \
		-I/usr/include
LDFLAGS+=	-L${BUILDLINK_DIR}/lib -lXft -lX11 -lfreetype -lXrender -lfontconfig \
		-lpng12 -lz -lm -lcrypt -lXmu -lpng -ljpeg

CUSTOM=


SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	slim.conf
SUBST_SED.conf+=	-e "s|/usr/local/bin:/usr/X11R6/bin|${PREFIX}/bin:${PREFIX}/${X11ROOT_PREFIX}/bin|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/X|${PREFIX}/${X11ROOT_PREFIX}/bin/X|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/xauth|${PREFIX}/${X11ROOT_PREFIX}/bin/xauth|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/xterm|${PREFIX}/bin/xterm|g"
SUBST_MESSAGE.conf=	Fixing hardcoded paths.

do-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} CC=${PKG_CC} CXX=${PKG_CXX} \
	    CFGDIR=${PKG_SYSCONFDIR} CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' CUSTOM='${CUSTOM}'

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/slim/themes/default
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/slim.theme \
	    ${PREFIX}/share/slim/themes/default/slim.theme
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/panel.png \
	    ${PREFIX}/share/slim/themes/default/panel.png
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/background.jpg \
	    ${PREFIX}/share/slim/themes/default/background.jpg
	cd ${WRKSRC} && ${INSTALL_PROGRAM} slim ${PREFIX}/sbin/slim
	cd ${WRKSRC} && ${INSTALL_MAN} slim.1 ${PREFIX}/${PKGMANDIR}/man1/slim.1
	cd ${WRKSRC} && ${INSTALL_DATA} slim.conf ${EGDIR}/slim.conf


.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
