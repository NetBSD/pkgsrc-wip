# $NetBSD$

DISTNAME=	python-decouple-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-decouple/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/henriquebastos/python-decouple/
COMMENT=	Strict separation of settings from code
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

WRKSRC=		${WRKDIR}/python-decouple-3.1
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
