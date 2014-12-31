# $NetBSD: Makefile,v 1.5 2014/12/31 13:58:36 thomasklausner Exp $

DISTNAME=	${PYPKGPREFIX}-pyprop-0.0
CATEGORIES=	math

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pyprop/
COMMENT=	Framework for propagating the TDSE written in Python/C++
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

# Get it from Subversion repository:
SVN_REPOSITORIES=	pyprop
SVN_ROOT.pyprop=  http://pyprop.googlecode.com/svn/trunk
SVN_MODULE.pyprop=	pyprop

WRKSRC=			${WRKDIR}/pyprop
CHECK_PORTABILITY_SKIP=  extern/blitz/source/configure extern/blitz/source/.svn/text-base/configure.svn-base

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
