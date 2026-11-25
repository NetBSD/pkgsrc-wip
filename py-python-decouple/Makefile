# $NetBSD$

DISTNAME=	python-decouple-3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-decouple/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/henriquebastos/python-decouple
COMMENT=	Strict separation of settings from code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
