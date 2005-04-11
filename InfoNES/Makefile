# $NetBSD: Makefile,v 1.2 2005/04/11 21:09:35 tvierling Exp $
#

DISTNAME=		InfoNES093J_Src
PKGNAME=		InfoNES-0.93
CATEGORIES=		emulators
MASTER_SITES=		http://www.geocities.co.jp/SiliconValley/5604/bin/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.geocities.co.jp/SiliconValley/5604/infones.html
COMMENT=		Portable NES emulator

BUILD_DIRS=		${WRKSRC}/linux
MAKE_VARS+=		INCLUDES="${CFLAGS} ${LIBOSSAUDIO}"

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	linux/InfoNES_System_Linux.cpp
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/InfoNES ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/InfoNES
	${INSTALL_DATA} ${FILESDIR}/keys.txt ${PREFIX}/share/doc/InfoNES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
