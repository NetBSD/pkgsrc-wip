# $NetBSD: Makefile,v 1.2 2015/01/03 11:31:11 nsloss Exp $
#

DISTNAME=	Nestopia140src
PKGNAME=	nestopia-rpi-1.40h
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nestopia/}
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} nst140_lnx_release_h.zip
SITES.nst140_lnx_release_h.zip=	http://rbelmont.mameworld.info/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rbelmont.mameworld.info/?page_id=200
COMMENT=	Portable, very accurate NES emulator with UNIF support
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

SUBST_CLASSES+=		oss
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.oss=	source/linux/oss.cpp
SUBST_MESSAGE.oss=	Fixing path to OSS device.
SUBST_STAGE.oss=	pre-build

INSTALLATION_DIRS=	bin share/doc/nestopia share/examples/nestopia

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nst ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.Linux \
		${DESTDIR}${PREFIX}/share/doc/nestopia
	${INSTALL_DATA} ${WRKSRC}/readme.html \
		${DESTDIR}${PREFIX}/share/doc/nestopia
	${INSTALL_DATA} ${WRKSRC}/NstDatabase.xml \
		${DESTDIR}${PREFIX}/share/examples/nestopia
	${INSTALL_DATA} ${WRKSRC}/nstcontrols \
		${DESTDIR}${PREFIX}/share/examples/nestopia

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
