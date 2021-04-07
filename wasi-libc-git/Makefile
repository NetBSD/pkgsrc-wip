# $NetBSD$

DISTNAME=	wasi-libc
PKGNAME=	wasi-libc-0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

GIT_REPOSITORIES=	wasi-libc
GIT_REPO.wasi-libc=	https://github.com/WebAssembly/wasi-libc.git
GIT_BRANCH.wasi-libc=	main
WRKSRC=			${WRKDIR}/wasi-libc

BUILD_DEPENDS+=	clang-[0-9]*:../../lang/clang # webassembly backend required

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://wasi.dev/
COMMENT=	WASI libc implementation for WebAssembly
LICENSE=	mit

USE_TOOLS+=	gmake
BUILD_TARGET=	default

MAKE_FLAGS+=	WASM_CC=${PREFIX}/bin/clang
MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/wasi

post-configure:
	mkdir ${WRKSRC}/build

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
