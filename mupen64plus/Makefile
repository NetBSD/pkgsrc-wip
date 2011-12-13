# $NetBSD: Makefile,v 1.1.1.1 2011/12/13 15:11:47 othyro Exp $
#

DISTNAME=	mupen64plus-bundle-src-1.99.4
PKGNAME=	${DISTNAME:S/-bundle-src//}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64plus.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mupen64plus/
COMMENT=	Cross-platform plugin-based N64 emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	cpuflags>=1.42:../../devel/cpuflags
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake pkg-config
USE_LIBTOOL=	yes
#CFLAGS+=	-DNO_ASM=1
MAKE_ENV+=	PLUGINDIR="${PREFIX}/lib/mupen64plus"
MAKE_ENV+=	SHAREDIR="${PREFIX}/share/mupen64plus"
INSTALL_ENV+=	PREFIX=${PREFIX}

.include "options.mk"

do-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} m64p_build.sh;

do-install:
		cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${BASH} m64p_install.sh;

#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
