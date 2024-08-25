# $NetBSD$

DISTNAME=	zig-git-0.11.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ziglang/}
GIT_REPO=	https://github.com/ziglang/zig.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	bash:run
USE_LANGUAGES=	c c++14

.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DDESTDIR=${DESTDIR}
# avoid full-cu-features available to build host,
# in other words ensure that we run everywhere
CMAKE_CONFIGURE_ARGS+=	-DZIG_TARGET_MCPU=baseline
CMAKE_CONFIGURE_ARGS+=	-DZIG_PIE=ON

REPLACE_BASH+=	lib/libcxxabi/src/demangle/cp-to-llvm.sh

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

UNLIMIT_RESOURCES=	stacksize

DEPENDS+=	llvm>=16.0.0:../../wip/llvm
DEPENDS+=	lld>=16.0.0:../../wip/lld
DEPENDS+=	clang>=16.0.0:../../wip/clang

CONFLICTS+=		zig-[0-9]*

INSTALLATION_DIRS+=	share/doc/zig

# after install, because the zig binary ends up in paths like
# ./zig-0.10.1/zig-cache/o/e6445b80597d6bc8fe865e7254800ac9/zig
# unless we want to run find for the executable here?
do-test:
	mkdir ${WRKDIR}/cache
	cd ${WRKSRC} && \
		${DESTDIR}${PREFIX}/bin/zig build test-behavior \
		--cache-dir ${WRKDIR}/cache --global-cache-dir ${WRKDIR}/cache \
		--zig-lib-dir ${WRKSRC}/lib

post-install:
	${MV} ${DESTDIR}${PREFIX}/doc/langref.html ${DESTDIR}${PREFIX}/share/doc/zig/langref.html

.include "../../wip/lld/buildlink3.mk"
.include "../../wip/clang/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
