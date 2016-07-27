# $NetBSD: Makefile,v 1.1 2013/02/07 21:23:33 othyro Exp $
#

DISTNAME=	higan_v092-source
PKGNAME=	${DISTNAME:S/_v0/-0./1:S/-source//1}
CATEGORIES=	emulators
MASTER_SITES=	http://higan.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://byuu.org/higan/
COMMENT=	Nintendo multi-system emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	platform=x compiler=gcc enable_gzip=true
CPPFLAGS+=	-I${PREFIX}/include
CXXFLAGS+=	-I${PREFIX}/include

# nullptr
GCC_REQD=	4.7

INSTALLATION_DIRS=	bin share/applications share/icons share/doc/higan

do-build:
	cd ${WRKSRC}/higan && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/higan/out/higan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/higan/data/higan.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/higan/data/higan.ico ${DESTDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/higan/data/higan.png ${DESTDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/higan/data/cheats.bml ${DESTDIR}${PREFIX}/share/doc/higan

.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
