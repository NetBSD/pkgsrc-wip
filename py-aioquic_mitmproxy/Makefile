# $NetBSD$

DISTNAME=	aioquic_mitmproxy-0.9.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioquic_mitmproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/meitinger/aioquic_mitmproxy
COMMENT=	Fork of aioquic with adjustments for mitmproxy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-pylsqpack>=0.3.3:../../wip/py-pylsqpack
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=22:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity>=23.1.0:../../security/py-service_identity

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
