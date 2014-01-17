# $NetBSD: Makefile,v 1.1 2014/01/17 21:48:13 jihbed Exp $

DISTNAME=	tardis-sn-0.9rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	tardis_sn-0.9rc1
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/t/tardis-sn/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tardis.readthedocs.org/
COMMENT=	TARDIS - Temperature And Radiative Diffusion In Supernovae
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.12.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../wip/py-h5py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
