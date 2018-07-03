# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:45 thomasklausner Exp $

DISTNAME=	tardis-sn-0.9rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tardis-sn/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tardis.readthedocs.org/
COMMENT=	TARDIS - Temperature And Radiative Diffusion In Supernovae
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.12.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-astropy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
