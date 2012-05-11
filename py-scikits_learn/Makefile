# $NetBSD: Makefile,v 1.2 2012/05/11 13:19:28 noud4 Exp $
#

DISTNAME=	scikits.learn-0.5
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|s.|s_|}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/scikit-learn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-learn.sourceforge.net/
COMMENT=	Set of python modules for machine learning and data mining
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++ fortran

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
