# $NetBSD: Makefile,v 1.1 2014/07/26 18:25:02 jihbed Exp $

DISTNAME=	HDDM-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=H/HDDM/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hddm-devs/hddm
COMMENT=	Hierarchical Bayesian estimation of Drift Diffusion Models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy

USE_LANGUAGES=	c fortran

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
