# $NetBSD: Makefile,v 1.5 2012/01/23 09:31:10 thomasklausner Exp $
#

DISTNAME=	bsnes_v085-source
PKGNAME=	${DISTNAME:S/_v0/-0./:S/-source//}
CATEGORIES=	emulators
MASTER_SITES=	http://bsnes.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.byuu.org/
COMMENT=	SNES emulator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/bsnes
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
