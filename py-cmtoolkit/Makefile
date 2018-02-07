# $NetBSD$

DISTNAME=	cmtoolkit-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmtoolkit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/AndrewWalker/cmtoolkit
COMMENT=	Unofficial Python port of the conformalmapping MATLAB toolbox
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
