# $NetBSD: Makefile,v 1.6 2014/01/25 10:38:23 thomasklausner Exp $

DISTNAME=	pysparse-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysparse/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysparse.sourceforge.net/
COMMENT=	Sparse linear algebra extension for Python
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++ fortran77
PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-Numeric

#.include "../../graphics/vtk-python/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
