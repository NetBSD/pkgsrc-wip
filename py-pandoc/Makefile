# $NetBSD$

DISTNAME=	pypandoc-1.16.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/0b/18/9f5f70567b97758625335209b98d5cb857e19aa1a9306e9749567a240634/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/JessicaTegner/pypandoc
COMMENT=	Thin wrapper for pandoc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.25.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
