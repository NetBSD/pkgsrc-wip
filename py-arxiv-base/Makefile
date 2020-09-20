# $NetBSD$

DISTNAME=	arxiv-base-0.16.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/d2/22/94b35de6cc93d5f7986496aeab60360cedde664e202b1cf4fa365cb51511/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/arxiv-base/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.14.46:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-bleach>=3.1.5:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-uwsgi-[0-9]*:../../www/py-uwsgi
DEPENDS+=	# TODO: backports-datetime-fromisoformat==1.0.0>=0


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
