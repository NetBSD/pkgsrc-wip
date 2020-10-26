# $NetBSD$

DISTNAME=	python-jose-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	security python
MASTER_SITES=   ${MASTER_SITE_PYPI:=p/python-jose/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/mpdavis/python-jose/
COMMENT=	JOSE implementation in Python
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=0:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.16.0:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-rsa>=4.6:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.4.8:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.9.8:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
