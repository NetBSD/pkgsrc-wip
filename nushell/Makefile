# $NetBSD: Makefile,v 1.58 2024/06/04 06:43:38 pin Exp $

DISTNAME=	nushell-0.95.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.77.2
USE_TOOLS+=	pkg-config

PKG_SHELL=	bin/nu

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
