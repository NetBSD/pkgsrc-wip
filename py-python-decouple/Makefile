# $NetBSD$

DISTNAME=	python-decouple-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-decouple/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/henriquebastos/python-decouple/
COMMENT=	Strict separation of settings from code
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

.include "../../lang/python/egg.mk"
WRKSRC=		${WRKDIR}/python-decouple-3.1
USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
