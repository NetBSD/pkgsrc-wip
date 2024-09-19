# $NetBSD$

DISTNAME=	pytest-html-1.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-html/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/pytest-dev/pytest-html
COMMENT=	Pytest plugin for generating HTML reports
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=3.5.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-metadata>=1.7.0:../../wip/py-test-metadata

.include "../../lang/python/egg.mk"
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
