# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:25 asau Exp $
#

DISTNAME=	pynetcdf-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pylab/PyNetCDF/0.7/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pynetcdf/0.7
COMMENT=	Python bindings for netcdf
#LICENSE=	cecill

PYDISTUTILSPKG= yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
