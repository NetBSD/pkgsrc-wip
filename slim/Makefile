# $NetBSD: Makefile,v 1.10 2010/12/26 05:01:23 davesainty Exp $
#

DISTNAME=	slim-1.3.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/slim/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://slim.berlios.de/
COMMENT=	SLiM is a Desktop-independent graphical login manager for X11

DEPENDS+=	xauth>=1.0.0:../../x11/xauth

USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/slim
CONF_FILES=	${EGDIR}/slim.conf ${PKG_SYSCONFDIR}/slim.conf

AUTO_MKDIRS=	yes
RCD_SCRIPTS+=	slim

CFLAGS+=	-I. -I${BUILDLINK_DIR}/include -I${BUILDLINK_DIR}/freetype2 \
		-I${BUILDLINK_DIR}/freetype2/config -I${BUILDLINK_DIR}/include/libpng14 \
		-I/usr/include
LDFLAGS+=	-L${BUILDLINK_DIR}/lib -lXft -lX11 -lfreetype -lXrender -lfontconfig \
		-lpng14 -lz -lm -lcrypt -lXmu -lpng -ljpeg

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	slim.conf
SUBST_SED.conf+=	-e "s|/usr/local/bin:/usr/X11R6/bin|${PREFIX}/bin:${PREFIX}/${X11ROOT_PREFIX}/bin|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/X|${PREFIX}/${X11ROOT_PREFIX}/bin/X|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/xauth|${PREFIX}/${X11ROOT_PREFIX}/bin/xauth|g"
SUBST_SED.conf+=	-e "s|/usr/X11R6/bin/xterm|${PREFIX}/bin/xterm|g"
SUBST_MESSAGE.conf=	Fixing hardcoded paths.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_FILE=	Makefile.netbsd
.elif ${OPSYS} == "DragonFly"
MAKE_FILE=	Makefile.netbsd
.elif ${OPSYS} == "FreeBSD"
MAKE_FILE=	Makefile.freebsd
.elif ${OPSYS} == "OpenBSD"
MAKE_FILE=	Makefile.openbsd
.else
USE_TOOLS+=	gmake
.endif

do-build:
	cd ${WRKSRC} && ${MAKE} -f ${MAKE_FILE} PREFIX=${PREFIX} CC=${PKG_CC} CXX=${PKG_CXX} \
		CFGDIR=${PKG_SYSCONFDIR} CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' CUSTOM='${CUSTOM}' \
		DESTDIR=${DESTDIR}

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/slim.theme \
		${DESTDIR}${PREFIX}/share/slim/themes/default/slim.theme
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/panel.png \
		${DESTDIR}${PREFIX}/share/slim/themes/default/panel.png
	cd ${WRKSRC} && ${INSTALL_DATA} themes/default/background.jpg \
		${DESTDIR}${PREFIX}/share/slim/themes/default/background.jpg
	cd ${WRKSRC} && ${INSTALL_PROGRAM} slim ${DESTDIR}${PREFIX}/sbin/slim
	cd ${WRKSRC} && ${INSTALL_MAN} slim.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/slim.1
	cd ${WRKSRC} && ${INSTALL_DATA} slim.conf ${DESTDIR}${EGDIR}/slim.conf

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
