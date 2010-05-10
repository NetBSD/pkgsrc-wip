# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:17:02 jihbed Exp $
#

DISTNAME=	pysparse-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pysparse/pysparse/1.1/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pysparse.sourceforge.net/
COMMENT=	Sparse linear algebra extension for Python
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	c c++ fortran
PYDISTUTILSPKG= yes

#.include "../../graphics/vtk-python/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
