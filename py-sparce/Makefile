# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	pysparse-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pysparse/pysparse/1.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysparse.sourceforge.net/
COMMENT=	Sparse linear algebra extension for Python
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++ fortran77
PYDISTUTILSPKG= yes

#.include "../../graphics/vtk-python/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
