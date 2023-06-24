# $NetBSD: Makefile,v 1.1 2013/07/07 12:48:16 othyro Exp $

DISTNAME=	mupen64plus-extraplugins-src-2.0.0
PKGNAME=	${DISTNAME:S/-src//1}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64plus.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mupen64plus/
COMMENT=	Additional Mupen64Plus plugins
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

BUILD_DIRS+=	mupen64plus-rsp-z64/projects/unix
BUILD_DIRS+=	mupen64plus-video-arachnoid/projects/unix
BUILD_DIRS+=	mupen64plus-video-glide64/projects/unix
BUILD_DIRS+=	mupen64plus-video-z64/projects/unix

MAKE_ENV+=	PLUGINDIR="${PREFIX}/lib/mupen64plus"
MAKE_ENV+=	SHAREDIR="${PREFIX}/share/mupen64plus"
MAKE_ENV+=	APIDIR="${PREFIX}/include/mupen64plus"
INSTALL_ENV+=	PREFIX=${PREFIX}

.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../wip/mupen64plus/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
TOOL_DEPENDS+=	cpuflags>=1.42:../../devel/cpuflags
.include "../../mk/bsd.pkg.mk"
