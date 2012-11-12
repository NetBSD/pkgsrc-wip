# $NetBSD: Makefile,v 1.4 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	scikits.learn-0.5
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|s.|s_|}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scikit-learn/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-learn.sourceforge.net/
COMMENT=	Set of python modules for machine learning and data mining
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	c c++ fortran

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
