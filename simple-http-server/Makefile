# $NetBSD$

DISTNAME=	simple-http-server-0.8.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheWaWaR/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheWaWaR/simple-http-server/
COMMENT=	Well, yet another simple HTTP server
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
