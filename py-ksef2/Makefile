# $NetBSD$

DISTNAME=	ksef2-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=artpods56/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/artpods56/ksef2/
COMMENT=	Python SDK and Tools for Poland's KSeF v2.0 API
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-cryptography>=44.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.9.9:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.12.5:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-signxml>=4.0:../../wip/py-signxml
DEPENDS+=	${PYPKGPREFIX}-structlog>=25.5.0:../../sysutils/py-structlog

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
