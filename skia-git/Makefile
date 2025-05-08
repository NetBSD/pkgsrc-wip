# $NetBSD$

# wip/ladybird-git wants milestone 129 exactly.
# Do not bump this unless ladybird does.
DISTNAME=	skia-129
CATEGORIES=	graphics

GIT_REPOSITORIES=	skia
GIT_REPO.skia=		https://skia.googlesource.com/skia.git
GIT_BRANCH.skia=	main
GIT_REVISION.skia=	a9019fddac2856b33f144d17d2de5c04e405b556

.include "git-depends.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://skia.org/
COMMENT=	2D graphics library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	gn-[0-9]*:../../wip/gn-git
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/skia

GN_ARGS+=	is_official_build=true
GN_ARGS+=	is_debug=false
GN_ARGS+=	skia_system_freetype2_include_path="${BUILDLINK_PREFIX.freetype2}/include/freetype2"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	third_party/harfbuzz/BUILD.gn
SUBST_FILES.paths+=	third_party/icu/BUILD.gn
SUBST_FILES.paths+=	third_party/libwebp/BUILD.gn
SUBST_FILES.paths+=	gn/skia/BUILD.gn
SUBST_FILES.paths+=	skia.pc
SUBST_VARS.paths+=	BUILDLINK_PREFIX.harfbuzz
SUBST_VARS.paths+=	BUILDLINK_PREFIX.libwebp
SUBST_VARS.paths+=	BUILDLINK_PREFIX.icu
SUBST_VARS.paths+=	X11BASE
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	PKGVERSION_NOREV

INSTALLATION_DIRS+=	include/skia/include/modules/skcms
INSTALLATION_DIRS+=	lib/pkgconfig

post-extract:
	${CP} ${FILESDIR}/skia.pc ${WRKSRC}

do-configure:
#	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/gn gen out/static --args='${GN_ARGS} is_component_build=false'
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/gn gen out/shared --args='${GN_ARGS} is_component_build=true'

do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/ninja -j ${_MAKE_JOBS_N} -C out/static
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/ninja -j ${_MAKE_JOBS_N} -C out/shared

do-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}/${PREFIX}/include/skia/include/.
	${INSTALL_DATA} ${WRKSRC}/modules/skcms/src/skcms_public.h ${DESTDIR}/${PREFIX}/include/skia/include/modules/skcms/skcms.h
	cd ${WRKSRC}/out/shared && ${PAX} -rw *.so *.a ${DESTDIR}/${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/skia.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/skia.pc

REQUIRED_REPOS+=	dng_sdk
REQUIRED_REPOS+=	piex
REQUIRED_REPOS+=	wuffs
REQUIRED_REPOS+=	zlib
.PHONY: git-depends.mk
git-depends.mk:
	${SETENV} REQUIRED_REPOS="${REQUIRED_REPOS}" ${AWK} -f ${FILESDIR}/gen-git-depends.awk < ${WRKSRC}/DEPS > ${.TARGET}.new
	mv ${.TARGET}.new ${.TARGET}

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
