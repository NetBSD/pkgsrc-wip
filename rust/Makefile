# $NetBSD: Makefile,v 1.7 2017/03/20 11:36:35 jperkin Exp $

DISTNAME=	rustc-1.17.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/
MASTER_SITES+=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		bash gmake

UNLIMIT_RESOURCES+=	cputime

# builtin LLVM pulls in c++11 and requires GCC 4.8
USE_LANGUAGES=		c c++11
GCC_REQD+=		4.8

REPLACE_BASH+=			src/rust-installer/gen-install-script.sh
REPLACE_BASH+=			src/rust-installer/gen-installer.sh
CHECK_PORTABILITY_SKIP=		src/rust-installer/gen-install*
CHECK_PORTABILITY_SKIP+=	src/grammar/check.sh

.include "../../mk/bsd.prefs.mk"

DISTFILES:=		${DEFAULT_DISTFILES}
RUST_STAGE0_VER=	1.16.0
CARGO_STAGE0_VER=	0.17.0

# If these are wrong, rust will begin fetching and creating these directories
# in rustc*-src/build/cache.
RUSTC_BULLSHIT:=	2017-03-11
CARGO_BULLSHIT:=	6b05583d71f982bcad049b9fa094c637c062e751
CARGO_DIRNAME:=		cargo-nightly-${RUST_MACHINE}.tar.gz

# Rust doesn't support pre-i686 Intel
.if ${MACHINE_ARCH} == "i386"
RUST_ARCH=		i686
.else
RUST_ARCH=		${MACHINE_ARCH}
.endif

.if !empty(LOWER_VENDOR)
RUST_VENDOR=		${LOWER_VENDOR}
.else
RUST_VENDOR=		unknown
.endif

RUST_MACHINE=		${RUST_ARCH}-${RUST_VENDOR}-${LOWER_OPSYS}

RUSTC_STAGE0:=		rustc-${RUST_STAGE0_VER}-${RUST_MACHINE}.tar.gz
RUST_STD_STAGE0:=       rust-std-${RUST_STAGE0_VER}-${RUST_MACHINE}.tar.gz
CARGO_STAGE0:=          cargo-${CARGO_STAGE0_VER}-${RUST_MACHINE}.tar.gz
DISTFILES:=             ${DISTFILES} ${RUSTC_STAGE0} ${RUST_STD_STAGE0} ${CARGO_STAGE0}

pre-extract:
	${MKDIR} ${WRKSRC}/build/cache/${RUSTC_BULLSHIT} \
	         ${WRKSRC}/build/cache/${CARGO_BULLSHIT}
	${CP} ${DISTDIR}/${RUSTC_STAGE0} ${WRKSRC}/build/cache/${RUSTC_BULLSHIT}
	${CP} ${DISTDIR}/${RUST_STD_STAGE0} ${WRKSRC}/build/cache/${RUSTC_BULLSHIT}
	${CP} ${DISTDIR}/${CARGO_STAGE0} ${WRKSRC}/build/cache/${CARGO_BULLSHIT}/${CARGO_DIRNAME}

do-configure:
	${CP} ${FILESDIR}/config.toml ${WRKSRC}/src/bootstrap

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	src/bootstrap/config.toml
SUBST_SED.paths=	-e 's,@@PREFIX@@,${PREFIX},'

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} x.py build

# XXX tell it where rustc is
#do-test:
#	cd ${WRKSRC}; ${PYTHONBIN} x.py test

BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags


# XXX using builtin LLVM
#.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
