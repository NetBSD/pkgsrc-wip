# $NetBSD$

DISTNAME=	ksef2-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=artpods56/}
GITHUB_PROJECT=	ksef2
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/artpods56/ksef2/
COMMENT=	Python SDK and Tools for Poland's KSeF v2.0 API
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.12.5:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-cryptography>=44.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-signxml>=4.0:../../wip/py-signxml
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-structlog>=25.5.0:../../sysutils/py-structlog
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.9.9:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-xsdata-pydantic>=24.5:../../wip/py-xsdata-pydantic
DEPENDS+=	${PYPKGPREFIX}-weasyprint>=63.0:../../print/py-weasyprint
DEPENDS+=	${PYPKGPREFIX}-tenacity>=9.0:../../devel/py-tenacity

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
