# $NetBSD$

DISTNAME=	truffleHog3-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/feeltheajf/truffleHog3
COMMENT=	Find secrets in your codebase
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gitpython>=3.1.10:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
