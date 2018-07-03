# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:29 thomasklausner Exp $

DISTNAME=	django-nose-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-nose/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/d/django-nose/
COMMENT=	Django test runner that uses nose
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.1.2

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/testapp && ${PYTHONBIN} runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
