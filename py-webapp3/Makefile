# $NetBSD$

DISTNAME=	webapp3-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/e6/aa/250684200e7804c22d76e1c34805d341782a05a61c50c0d808e142ca58c3/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/webapp3/
COMMENT=	Python web framework compatible with Google App Engines webapp
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.8.5:../../www/py-WebOb

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
