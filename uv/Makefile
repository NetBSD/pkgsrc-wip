# $NetBSD$

DISTNAME=	uv-0.5.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=astral-sh/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://docs.astral.sh/uv/
COMMENT=	Extremely fast Python package and project manager
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

RUST_REQ=	1.81

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
