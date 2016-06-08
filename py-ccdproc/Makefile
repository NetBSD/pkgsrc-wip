# $NetBSD: Makefile,v 1.1 2015/07/10 22:45:07 jihbed Exp $

DISTNAME=	ccdproc-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ccdproc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ccdproc.readthedocs.org/
COMMENT=	Stropy affiliated package
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.4.6:../../wip/py-astropy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
