# $NetBSD$

# Upstream master; needs LLVM 23 (wip/llvm) while lang/zig follows lang/llvm.
# When bumping GIT_REVISION, update ZIG_DEV to match `git describe --tags`
# (0.17.0-<ZIG_DEV>-g<hash>) of that commit.
ZIG_DEV=	624
GIT_REVISION=	b7f2c6d8fefdd2747e39e930bbe2c9450ec8f07c

DISTNAME=	zig-git-0.18.0pre${ZIG_DEV}
CATEGORIES=	lang
GIT_REPO=	https://codeberg.org/ziglang/zig.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

# Fails to build in chroot on netbsd: https://github.com/ziglang/zig/issues/19756
USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run

# Avoid WRKREF in RUNPATH of bin/zig.
CONFIGURE_ENV+=		CMAKE_PREFIX_PATH=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX}

# The checkout has no tags, so `git describe` cannot derive the version.
CMAKE_CONFIGURE_ARGS+=	-DZIG_VERSION=0.18.0-dev.${ZIG_DEV}+${GIT_REVISION:C/^(.........).*/\1/}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DZIG_SHARED_LLVM=ON
# avoid full-cpu-features available to build host,
# in other words ensure that we run everywhere
CMAKE_CONFIGURE_ARGS+=	-DZIG_TARGET_MCPU=baseline

MAKE_ENV+=	ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/zig-global-cache
MAKE_ENV+=	ZIG_LOCAL_CACHE_DIR=${WRKDIR}/zig-local-cache

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

UNLIMIT_RESOURCES=	stacksize

RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no

CONFLICTS+=	zig-[0-9]*

# after install, because the zig binary ends up in paths like
# ./zig-0.10.1/zig-cache/o/e6445b80597d6bc8fe865e7254800ac9/zig
# unless we want to run find for the executable here?
do-test:
	mkdir ${WRKDIR}/cache
	cd ${WRKSRC} && \
		${DESTDIR}${PREFIX}/bin/zig build test-behavior \
		--cache-dir ${WRKDIR}/cache --global-cache-dir ${WRKDIR}/cache \
		--zig-lib-dir ${WRKSRC}/lib

.include "../../devel/cmake/build.mk"
.include "../../wip/lld/buildlink3.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
