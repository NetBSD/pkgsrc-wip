# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	obspy-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/o/obspy/
EXTRACT_SUFX=	.zip#md5=9da79d3a0604d433085ad4dc0e430100
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.obspy.org/
COMMENT=	Python framework for seismological observatories
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-suds>=0.4:../../net/py-suds
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.3:../../textproc/py-lxml

USE_LANGUAGES=	c fortran

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-suds

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
