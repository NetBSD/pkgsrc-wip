# $NetBSD: Makefile,v 1.6 2013/01/14 17:17:41 othyro Exp $
#

DISTNAME=	mupen64plus-bundle-src-1.99.5
PKGNAME=	${DISTNAME:S/-bundle-src//}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64plus.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mupen64plus/
COMMENT=	Cross-platform plugin-based N64 emulator
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	cpuflags>=1.42:../../devel/cpuflags
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake pkg-config
USE_LIBTOOL=	yes
#CFLAGS+=	-DNO_ASM=1
MAKE_ENV+=	PLUGINDIR="${PREFIX}/lib/mupen64plus"
MAKE_ENV+=	SHAREDIR="${PREFIX}/share/mupen64plus"
INSTALL_ENV+=	PREFIX=${PREFIX}
INSTALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "options.mk"


do-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} m64p_build.sh;

do-install:
		cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${BASH} m64p_install.sh;


BUILD_DEPENDS+=	glu-[0-9]*:../../graphics/glu
BUILD_DEPENDS+=	MesaLib-[0-9]*:../../graphics/MesaLib
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILD_DEPENDS+=	freetype2-[0-9]*:../../graphics/freetype2
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
