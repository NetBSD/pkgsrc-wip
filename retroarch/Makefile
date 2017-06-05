# $NetBSD: Makefile,v 1.6 2015/04/25 14:20:47 tnn Exp $

DISTNAME=	retroarch-1.6.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	http://www.retroarch.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	RetroArch
GITHUB_TAG=	v${PKGVERSION_NOREV}

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=--global-config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--disable-builtinminiupnpc
CONFIGURE_ARGS+=--disable-builtinzlib

CONFIGURE_ENV+= BIN_DIR=${PREFIX}/bin
CONFIGURE_ENV+= MAN_DIR=${PREFIX}/${PKGMANDIR}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=	tools/cg2glsl.py

DEPENDS+=	libretro-core-info>0:../../wip/libretro-core-info
DEPENDS+=	retroarch-assets>0:../../wip/retroarch-assets

EGDIR=		${PREFIX}/share/examples/retroarch
CONF_FILES+=	${EGDIR}/retroarch.cfg ${PKG_SYSCONFDIR}/retroarch.cfg

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		qb/config.libs.sh
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_MESSAGE.cfg=	Setting paths in sample config.
SUBST_FILES.cfg=	retroarch.cfg
SUBST_SED.cfg+=		-e 's;\# libretro_directory =.*;libretro_directory = "${PREFIX}/lib/libretro";'
SUBST_SED.cfg+=		-e 's;\# libretro_info_path =.*;libretro_info_path = "${PREFIX}/share/libretro/info";'
SUBST_SED.cfg+=		-e 's;\# assets_directory =.*;assets_directory = "${PREFIX}/share/libretro/assets";'

CONFIGURE_ARGS+=	--disable-x11	# broken, SDL2 works

.include "../../mk/bsd.fast.prefs.mk"

# On exit:
# assertion "pthread__tsd_destructors[key] != NULL" failed:
# file "/usr/src/lib/libpthread/pthread_tsd.c", line 287, function "pthread_key_delete"
# [1]   Abort trap (core dumped) retroarch
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-thread_storage
.endif

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
