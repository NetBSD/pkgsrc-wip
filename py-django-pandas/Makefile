# $NetBSD$

DISTNAME=	django-pandas-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-pandas/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/chrisdev/django-pandas/
COMMENT=	Tools for working with pydata.pandas in your Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-semver>=2.10.1:../../wip/py-semver

do-test:
	cd $(WRKSRC} && ${PYTHONBIN} runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
