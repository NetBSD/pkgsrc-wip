# $NetBSD$

DISTNAME=	django-stubs-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.deposit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/typeddjango/django-stubs
COMMENT=	Mypy stubs for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy>=0.790:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-django>=1.11.29:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
