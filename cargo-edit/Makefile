# $NetBSD: Makefile,v 1.1 2025/01/24 13:25:56 pin Exp $

DISTNAME=	cargo-edit-0.13.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=killercup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/killercup/cargo-edit/
COMMENT=	Utility for managing cargo dependencies from the command line
LICENSE=	mit

SITES.curl-sys-0.4.78+curl-8.11.0.crate=	https://static.crates.io/crates/curl-sys/
SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUST_REQ=	1.85.0 # edition = "2024"
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
