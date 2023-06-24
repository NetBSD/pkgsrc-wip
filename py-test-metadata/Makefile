# $NetBSD$

DISTNAME=	pytest-metadata-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-metadata/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/pytest-dev/pytest-metadata
COMMENT=	Plugin for test session metadata
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

DEPENDS+=	${PYPKGPREFIX}-test>=3.5.0:../../devel/py-test

.include "../../lang/python/egg.mk"
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
