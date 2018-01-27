# $NetBSD: Makefile,v 1.1 2015/08/05 21:56:30 jihbed Exp $

DISTNAME=	naima-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=n/naima/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/zblz/naima
COMMENT=	Derivation of non-thermal particle through MCMC spectral fitting
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.4.6:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-emcee>=2.1.0:../../wip/py-emcee

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
