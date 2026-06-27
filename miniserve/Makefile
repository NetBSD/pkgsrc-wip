# $NetBSD$

DISTNAME=	miniserve-0.35.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=svenstaro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/svenstaro/miniserve/
COMMENT=	CLI tool to serve files and dirs over HTTP
LICENSE=	mit

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
