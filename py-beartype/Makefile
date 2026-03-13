# $NetBSD$

DISTNAME=	beartype-0.22.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=beartype/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/beartype/beartype/
COMMENT=	The bare-mental type checker
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
