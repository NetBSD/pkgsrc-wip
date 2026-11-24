# $NetBSD$

DISTNAME=	viddy-1.3.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sachaos/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/sachaos/viddy/
COMMENT=	Modern watch command
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
