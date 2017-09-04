# $NetBSD: Makefile,v 1.7 2017/03/20 11:36:35 jperkin Exp $

DISTNAME=	rustc-1.19.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/
MASTER_SITES+=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		bash gmake

UNLIMIT_RESOURCES+=	cputime

# builtin LLVM pulls in c++11 and requires GCC 4.8
USE_LANGUAGES=		c c++11
GCC_REQD+=		4.8

.include "../../mk/bsd.prefs.mk"

DISTFILES:=		${DEFAULT_DISTFILES}
RUST_STAGE0_VER=	1.18.0
CARGO_STAGE0_VER=	0.19.0
# If this wrong, rust will begin fetching and creating these directories
# in rustc*-src/build/cache.
CARGO_DIRNAME=		${WRKSRC}/build/cache/2017-06-08

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

RUSTC_STAGE0=		rustc-${RUST_STAGE0_VER}-${RUST_MACHINE}.tar.gz
RUST_STD_STAGE0=	rust-std-${RUST_STAGE0_VER}-${RUST_MACHINE}.tar.gz
CARGO_STAGE0=		cargo-${CARGO_STAGE0_VER}-${RUST_MACHINE}.tar.gz
DISTFILES+=		${RUSTC_STAGE0} ${RUST_STD_STAGE0} ${CARGO_STAGE0}

pre-extract:
	${MKDIR} ${CARGO_DIRNAME}
	${CP} ${DISTDIR}/${RUSTC_STAGE0} ${CARGO_DIRNAME}
	${CP} ${DISTDIR}/${RUST_STD_STAGE0} ${CARGO_DIRNAME}
	${CP} ${DISTDIR}/${CARGO_STAGE0} ${CARGO_DIRNAME}

do-configure:
	${CP} ${FILESDIR}/config.toml ${WRKSRC}/src/bootstrap/config.toml

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	src/bootstrap/config.toml
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},'

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} x.py build --verbose

do-install:
	cd ${WRKSRC}; ${PYTHONBIN} x.py install --verbose

# XXX tell it where rustc is
#do-test:
#	cd ${WRKSRC}; ${PYTHONBIN} x.py test

BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags


# Package maintenance bits

# invoke "make mdi PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)

# When adding a target here, also add it to available.mk
RUST_MACHINES=	i686-apple-darwin \
		x86_64-apple-darwin \
		i686-unknown-linux-gnu \
		x86_64-unknown-linux-gnu \
		x86_64-unknown-netbsd \
#		x86_64-sun-solaris

.for MACHINE in ${RUST_MACHINES}
RUSTCS+=	rustc-${RUST_STAGE0_VER}-${MACHINE}.tar.gz
RUST_STDS+=	rust-std-${RUST_STAGE0_VER}-${MACHINE}.tar.gz
CARGOS+=	cargo-${CARGO_STAGE0_VER}-${MACHINE}.tar.gz
.endfor

DISTFILES+=	${RUSTCS} ${RUST_STDS} ${CARGOS}

.endif


# XXX using builtin LLVM
#.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
