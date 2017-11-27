# $NetBSD: Makefile,v 1.6 2015/04/25 14:20:47 tnn Exp $

DISTNAME=	retroarch-1.6.9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	http://www.retroarch.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	RetroArch
GITHUB_TAG=	v${PKGVERSION_NOREV}

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=--disable-builtinminiupnpc
CONFIGURE_ARGS+=--disable-builtinzlib

CONFIGURE_ENV+=	BIN_DIR=${PREFIX}/bin
CONFIGURE_ENV+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

DEPENDS+=	libretro-database>0:../../wip/libretro-database
DEPENDS+=	libretro-core-info>0:../../wip/libretro-core-info
DEPENDS+=	libretro-glsl-shaders>0:../../wip/libretro-glsl-shaders
DEPENDS+=	retroarch-assets>0:../../wip/retroarch-assets

CPPFLAGS+=	-DPREFIX=\"${PREFIX}\"

.include "../../mk/bsd.fast.prefs.mk"

# On exit (load a game first):
# assertion "pthread__tsd_destructors[key] != NULL" failed:
# file "/usr/src/lib/libpthread/pthread_tsd.c", line 287, function "pthread_key_delete"
# [1]   Abort trap (core dumped) retroarch
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=       --disable-thread_storage
.endif

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
