# $NetBSD$

DISTNAME=	sym-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/f5/07/cc80b30b933c7430597fc884305c499e973f2e4c0a3a6208880ced5cefba/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/sym
COMMENT=	Unified wrapper for symbolic manipulation libraries in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
