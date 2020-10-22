# $NetBSD$

VERS=		2.1.0
DISTNAME=	scanapi-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://scanapi.dev/
COMMENT=	Automated Testing and Documentation for your REST API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.00:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-curlify>=2.2.1:../../wip/py-curlify

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
