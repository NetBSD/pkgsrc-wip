# $NetBSD$

DISTNAME=	Flask-RESTful-0.3.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=   ${MASTER_SITE_PYPI:=F/Flask-RESTful/}

MAINTAINER=     kethzer.dr@gmail.com
HOMEPAGE=	https://www.github.com/flask-restful/flask-restful/
COMMENT=	Simple framework for creating REST APIs
LICENSE=	modified-bsd


DEPENDS+=       ${PYPKGPREFIX}-sphinx>=1.6.3:../../textproc/py-sphinx
DEPENDS+=       ${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto
DEPENDS+=       ${PYPKGPREFIX}-flask>=0.10:../../www/py-flask
DEPENDS+=       ${PYPKGPREFIX}-six>=1.3.0:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-six>=[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
WRKSRC=		${WRKDIR}/Flask-RESTful-0.3.6
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
