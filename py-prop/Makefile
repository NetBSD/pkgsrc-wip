# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:23:16 jihbed Exp $
#

DISTNAME=	${PYPKGPREFIX}-pyprop
#EGG_NAME=	pydec-1.0.0.dev14
CATEGORIES=	physcis python

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pyprop/
COMMENT=	A framework for propagating the time dependent Schrödinger equation (TDSE) written in Python/C++
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

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
