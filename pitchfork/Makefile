# $NetBSD$

DISTNAME=	pitchfork-2.13.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=endevco/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pitchfork.en.dev/
COMMENT=	Devilishly good process manager for developers
LICENSE=	mit

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
