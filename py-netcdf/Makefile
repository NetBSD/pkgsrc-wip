# $NetBSD: Makefile,v 1.1.1.1 2009/08/31 00:34:12 jihbed Exp $
#

DISTNAME=	pynetcdf-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pylab/PyNetCDF/0.7/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pynetcdf/0.7
COMMENT=	Python bindings for netcdf
#LICENSE=	cecill

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
