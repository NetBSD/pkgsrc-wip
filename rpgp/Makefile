# $NetBSD$

DISTNAME=	rpgp-0.11.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpgp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpgp/rpgp/
COMMENT=	Pure rust implementation of OpenPGP
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
