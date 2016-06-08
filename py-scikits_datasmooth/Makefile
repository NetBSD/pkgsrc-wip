# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:16 othyro Exp $
#

DISTNAME=	scikits.datasmooth-0.5
PKGNAME=	${PYPKGPREFIX}-scikits_datasmooth-0.5
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.datasmooth/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikits.appspot.com/
COMMENT=	Scikits data smoothing package
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
