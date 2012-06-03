# $NetBSD: Makefile,v 1.7 2012/06/03 12:37:06 othyro Exp $
#

DISTNAME=	bsnes_v089
PKGNAME=	${DISTNAME:S/_v0/-0./}
CATEGORIES=	emulators
MASTER_SITES=	http://bsnes.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.byuu.org/bsnes/
COMMENT=	SNES emulator
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/bsnes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	platform=x compiler=gcc enable_gzip=true
CPPFLAGS+=	-I${PREFIX}/include
CXXFLAGS+=	-I${PREFIX}/include

# nullptr
GCC_REQD=	4.6

INSTALLATION_DIRS=	bin share/applications share/icons share/doc/bsnes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/bsnes ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/bsnes.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/bsnes.png ${DESTDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/data/cheats.xml ${DESTDIR}${PREFIX}/share/doc/bsnes

.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
