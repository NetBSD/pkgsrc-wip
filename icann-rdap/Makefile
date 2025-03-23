# $NetBSD$

DISTNAME=	icann-rdap-0.0.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=icann/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/icann/icann-rdap/
COMMENT=	ICANN RDAP client + server
LICENSE=	apache-2.0 OR mit

RCD_SCRIPTS+=		rdap-srv
PKG_RCD_SCRIPTS=	no

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

#RUST_REQ=	1.85.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.85.1 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-test \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv-data \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv-store \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
