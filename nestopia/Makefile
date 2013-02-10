# $NetBSD: Makefile,v 1.3 2013/02/10 12:31:01 thomasklausner Exp $
#

DISTNAME=	nestopia-1.44
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nestopiaue/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rbelmont.mameworld.info/?page_id=200
COMMENT=	Portable, very accurate NES emulator with UNIF support
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

SUBST_CLASSES+=		oss
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss=	source/unix/oss.cpp
SUBST_MESSAGE.oss=	Fixing path to OSS device.
SUBST_STAGE.oss=	pre-build

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

INSTALLATION_DIRS=	share/doc/nestopia

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.unix \
		${DESTDIR}${PREFIX}/share/doc/nestopia
	${INSTALL_DATA} ${WRKSRC}/readme.html \
		${DESTDIR}${PREFIX}/share/doc/nestopia

.include "../../sysutils/desktop-file-utils/buildlink3.mk"
BUILD_DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
