# $NetBSD$

DISTNAME=	xt-0.18.2
CATEGORIES=	textproc
MASTER_SITES=	https://static.crates.io/crates/xt/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahamlinman/xt/
COMMENT=	Translate between serialized data formats
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
