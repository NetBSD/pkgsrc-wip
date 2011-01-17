# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:17:27 jihbed Exp $
#

DISTNAME=	scikits.learn-0.5
EGG_NAME=	scikits.learn-0.5
PKGNAME=	${PYPKGPREFIX}-scikits_learn-0.5
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/scikit-learn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-learn.sourceforge.net/
COMMENT=	Set of python modules for machine learning and data mining
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++ fortran

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
