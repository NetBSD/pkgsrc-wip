# $NetBSD$

DISTNAME=	cargo-deb-2.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kornelski/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/kornelski/cargo-deb
COMMENT=	Cargo helper to build Debian packages
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.71.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
