# $NetBSD: Makefile,v 1.18 2024/05/07 07:18:55 wiz Exp $

DISTNAME=	cargo-c-0.10.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lu-zero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/lu-zero/cargo-c
COMMENT=	Build and install C-compatible libraries from Rust lang
LICENSE=	2-clause-bsd

SITES.curl-sys-0.4.80+curl-8.12.1.crate=	https://static.crates.io/crates/curl-sys/
SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.13.3+wasi-0.2.2.crate=		https://static.crates.io/crates/wasi/

USE_TOOLS+=	pkg-config

RUST_REQ=	1.83.0
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGOC_PROGRAMS+=	cargo-capi
CARGOC_PROGRAMS+=	cargo-cbuild
CARGOC_PROGRAMS+=	cargo-cinstall
CARGOC_PROGRAMS+=	cargo-ctest

do-install:
.for f in ${CARGOC_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
