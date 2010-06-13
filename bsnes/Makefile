# $NetBSD: Makefile,v 1.4 2010/06/13 22:46:57 thomasklausner Exp $
#

DISTNAME=	bsnes_v039
PKGNAME=	${DISTNAME:S/_v0/-0./}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://byuu.cinnamonpirate.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.byuu.org/
COMMENT=	SNES emulator

WRKSRC=		${WRKDIR}/src
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	platform=x compiler=gcc enable_gzip=true

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bsnes ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/bsnes.png ${DESTDIR}${PREFIX}/share/icons

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
