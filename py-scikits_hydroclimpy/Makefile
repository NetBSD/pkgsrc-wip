# $NetBSD: Makefile,v 1.1.1.1 2011/03/22 08:19:47 jihbed Exp $
#

DISTNAME=	${PYPKGPREFIX}-scikits_hydroclimpy-0.67.0
CATEGORIES=	science python

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hydroclimpy.sourceforge.net/
COMMENT=	Tools to manipulate environmental and climatologic time series

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+= c  fortran

# Get it from Subversion repository:
SVN_REPOSITORIES=	hydroclimpy
SVN_ROOT.hydroclimpy= http://svn.scipy.org/svn/scikits/trunk/hydroclimpy
SVN_MODULE.hydroclimpy=	hydroclimpy

WRKSRC=			${WRKDIR}/hydroclimpy

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
