# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	tinygo-0.42.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=tinygo-org/}

GITHUB_SUBMODULES+=	NordicSemiConductor nrfx d779b49fc59c7a165e7da1d7cd7d57b28a059f16 lib/nrfx
GITHUB_SUBMODULES+=	ARM-software CMSIS 9fe411cef1cef5de58e5957b89760759de44e393 lib/CMSIS
GITHUB_SUBMODULES+=	avr-rust avr-mcu 6624554c02b237b23dc17d53e992bf54033fc228 lib/avr
GITHUB_SUBMODULES+=	cmsis-svd cmsis-svd-data 05a9562ec59b87945a8d7177a4b08b7aa2f2fd58 lib/cmsis-svd
GITHUB_SUBMODULES+=	WebAssembly wasi-libc 1dfe5c302d1c5ab621f7abf04620fae92700fd22 lib/wasi-libc
GITHUB_SUBMODULES+=	keith-packard picolibc b92edfda8ac6853772d87cadaeeeaa21b78609b6 lib/picolibc
GITHUB_SUBMODULES+=	tinygo-org py32-svd 6aa7396c1d4d20be61cc62f283fa3835665c7361 lib/py32-svd
GITHUB_SUBMODULES+=	tinygo-org stm32-svd bfed180b639863db414221bdb6aa77e198f464f5 lib/stm32-svd
# musl: handled via distfile
# binaryen: use devel/binaryen instead
GITHUB_SUBMODULES+=	mingw-w64 mingw-w64 8526cb618269440a94810b94b77f8bd48c5c3396 lib/mingw-w64
GITHUB_SUBMODULES+=	aykevl macos-minimal-sdk 5f57dee4ae50adb8062f53419e535f6aa065f699 lib/macos-minimal-sdk
GITHUB_SUBMODULES+=	tinygo-org net 70037cf71f1ae14175781e162c9c76d1ac730ece src/net
GITHUB_SUBMODULES+=	WebAssembly wasi-cli 6ae82617096e83e6606047736e84ac397b788631 lib/wasi-cli
GITHUB_SUBMODULES+=	ivmai bdwgc 7577ca7c2dc7364bb6733dab23be34231279db6b lib/bdwgc

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/tinygo-org/tinygo/
COMMENT=	Go compiler for small places
LICENSE=	modified-bsd AND apache-2.0

TINYGO_DISTFILES+=			musl-1.2.6.tar.gz
SITES.musl-1.2.6.tar.gz=		https://musl.libc.org/releases/
TINYGO_DISTFILES+=			llvm-project-2be7242.tar.gz
SITES.llvm-project-2be7242.tar.gz=	-https://github.com/tinygo-org/llvm-project/archive/2be7242b6a4d59fe89fb43f7d1e7333dc9b307a2.tar.gz

DEPENDS+=	binaryen-[0-9]*:../../devel/binaryen
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

MAKE_ENV+=	USE_SYSTEM_BINARYEN=1
MAKE_ENV+=	NINJA_EXTRA_ARGS="-j ${MAKE_JOBS:U1}"
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax

CHECK_INTERPRETER_SKIP+=	tinygo/lib/macos-minimal-sdk/generate-stubs.py
CHECK_INTERPRETER_SKIP+=	tinygo/lib/picolibc/newlib/libc/string/uniset
CHECK_INTERPRETER_SKIP+=	tinygo/lib/picolibc/newlib/libc/tinystdio/make-dtoa-data

DISTFILES=		${DEFAULT_DISTFILES} ${TINYGO_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES} ${TINYGO_DISTFILES} ${_GITHUB_DEFAULT_DISTFILES}

.include "go-modules.mk"

post-extract:
	mv ${WRKDIR}/llvm-project* ${WRKSRC}/llvm-project
	rm -rf ${WRKSRC}/lib/musl && mv ${WRKDIR}/musl* ${WRKSRC}/lib/musl

do-build:
.for t in llvm-build tinygo build/release
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} ${t}
.endfor

do-install:
	cd ${WRKSRC}/build/release && pax -rw tinygo ${DESTDIR}${PREFIX}

.include "../../lang/go/go-module.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
