# $NetBSD$

DISTNAME=	rustormy-0.3.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tairesh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Tairesh/rustormy/
COMMENT=	Minimal neofetch-like weather CLI
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.89.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.89.0 on amd64

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
