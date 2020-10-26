# $NetBSD$

DISTNAME=	pydata-google-auth-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydata-google-auth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pydata/pydata-google-auth
COMMENT=	PyData helpers for authenticating to Google APIs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.22.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0.4.1:../../security/py-google-auth-oauthlib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
