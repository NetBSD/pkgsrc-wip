# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	tinygo-0.30.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=tinygo-org/}

GITHUB_SUBMODULES+=	NordicSemiConductor nrfx d779b49fc59c7a165e7da1d7cd7d57b28a059f16 lib/nrfx
GITHUB_SUBMODULES+=	ARM-software CMSIS 9fe411cef1cef5de58e5957b89760759de44e393 lib/CMSIS
GITHUB_SUBMODULES+=	avr-rust avr-mcu 6624554c02b237b23dc17d53e992bf54033fc228 lib/avr
GITHUB_SUBMODULES+=	tinygo-org cmsis-svd df75ff974c76a911fc2815e29807f5ecaae06fc2 lib/cmsis-svd
GITHUB_SUBMODULES+=	CraneStation wasi-libc 30094b6ed05f19cee102115215863d185f2db4f0 lib/wasi-libc
GITHUB_SUBMODULES+=	keith-packard picolibc b92edfda8ac6853772d87cadaeeeaa21b78609b6 lib/picolibc
GITHUB_SUBMODULES+=	tinygo-org stm32-svd e6db8e32d5d42293a528434ec12e7f88479a8649 lib/stm32-svd
# musl: handled via distfile
# binaryen: use devel/binaryen instead
GITHUB_SUBMODULES+=	mingw-w64 mingw-w64 8526cb618269440a94810b94b77f8bd48c5c3396 lib/mingw-w64
GITHUB_SUBMODULES+=	aykevl macos-minimal-sdk ebb736fda2bec7cea38dcda807518b835a539525 lib/macos-minimal-sdk
GITHUB_SUBMODULES+=	tinygo-org renesas-svd 03d76880854b9042f5d043f4355cdf8eef522fa5 lib/renesas-svd

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/tinygo-org/tinygo/
COMMENT=	Go compiler for small places
LICENSE=	modified-bsd AND apache-2.0

DISTFILES=				${DEFAULT_DISTFILES}
DISTFILES+=				musl-1.2.4.tar.gz
SITES.musl-1.2.4.tar.gz=		https://www.musl-libc.org/releases/
DISTFILES+=				esp-16.0.4-20231113.tar.gz
SITES.esp-16.0.4-20231113.tar.gz=	https://github.com/espressif/llvm-project/archive/refs/tags/

DEPENDS+=	binaryen-[0-9]*:../../devel/binaryen
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

MAKE_ENV+=	GIT_SHA1=731532c
MAKE_ENV+=	USE_SYSTEM_BINARYEN=1
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax

CHECK_INTERPRETER_SKIP+=	tinygo/lib/macos-minimal-sdk/generate-stubs.py
CHECK_INTERPRETER_SKIP+=	tinygo/lib/picolibc/newlib/libc/string/uniset
CHECK_INTERPRETER_SKIP+=	tinygo/lib/picolibc/newlib/libc/tinystdio/make-dtoa-data

.include "go-modules.mk"

post-extract:
	mv ${WRKDIR}/llvm-project* ${WRKSRC}/llvm-project
	rm -rf ${WRKSRC}/lib/musl && mv ${WRKDIR}/musl* ${WRKSRC}/lib/musl
	cp ${WRKDIR}/go.bug.st/serial@v1.6.0/serial_openbsd.go		\
		${WRKDIR}/go.bug.st/serial@v1.6.0/serial_netbsd.go
	cp ${WRKDIR}/go.bug.st/serial@v1.6.0/enumerator/usb_openbsd.go	\
		${WRKDIR}/go.bug.st/serial@v1.6.0/enumerator/usb_netbsd.go

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
