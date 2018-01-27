# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:47 othyro Exp $
#

DISTNAME=	pynetcdf-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylab/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pynetcdf/0.7
COMMENT=	Python bindings for netcdf
#LICENSE=	cecill

PYDISTUTILSPKG=	yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
