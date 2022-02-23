# $NetBSD$

DISTNAME=	typing_inspect-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing_inspect/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ilevkivskyi/typing_inspect
COMMENT=	Runtime inspection utilities for typing module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.3.0:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
DEPENDS+=	${PYPKGPREFIX}-typing>=3.7.4:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
