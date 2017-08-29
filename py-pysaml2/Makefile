# $NetBSD$

DISTNAME=	pysaml2-4.4.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=   ${MASTER_SITE_PYPI:=p/pysaml2/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/rohe/pysaml2
COMMENT=	Python implementation of SAML Version 2
LICENSE=	apache-2.0

DEPENDS+= ${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+= ${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+= ${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+= ${PYPKGPREFIX}-Paste-[0-9]*:../../www/py-paste
DEPENDS+= ${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+= ${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+= ${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+= ${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+= ${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
