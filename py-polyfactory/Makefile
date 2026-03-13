# $NetBSD$

DISTNAME=	polyfactory-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=litestar-org/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/litestar-org/polyfactory/
COMMENT=	Mock data generation library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-faker>=5.0.0:../../devel/py-faker
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
