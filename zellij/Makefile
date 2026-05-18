# $NetBSD$

GITHUB_TAG=	b558b31ed192652f75ecc35d6753a7d5d0046023
DISTNAME=	zellij-${GITHUB_TAG}
PKGNAME=	zellij-0.45.0pre20250516
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zellij-org/}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zellij.dev/
COMMENT=	Terminal workspace with batteries included
LICENSE=	mit

.include "cargo-depends.mk"

SITES.curl-sys-0.4.68+curl-8.4.0.crate=	https://static.crates.io/crates/curl-sys/

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake perl

PREPEND_PATH+=	${PREFIX}/gnu/bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
