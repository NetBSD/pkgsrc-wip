# $NetBSD$

DISTNAME=	postorius-1.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postorius/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	The New Mailman Web UI
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-django-mailman3>=1.3.8:../../wip/py-django-mailman3
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../wip/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-readme_renderer-[0-9]*:../../textproc/py-readme_renderer

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
