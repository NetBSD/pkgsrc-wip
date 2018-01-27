# $NetBSD: Makefile,v 1.1 2015/07/11 00:59:05 jihbed Exp $

DISTNAME=	reducer-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reducer/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mwcraig/reducer
COMMENT=	Process FITS files
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ipython>=2.0.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.4.6:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-ccdproc>=0.3.1:../../wip/py-ccdproc
DEPENDS+=	${PYPKGPREFIX}-msumastro>=0.8.2:../../wip/py-msumastro


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
