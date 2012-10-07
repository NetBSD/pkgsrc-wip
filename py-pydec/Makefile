# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	${PYPKGPREFIX}-pydec-0.67.0
PKGREVISION=	3
EGG_NAME=	pydec-1.0.0.dev29
CATEGORIES=	science python

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pydec/
COMMENT=	Python Library for Discrete Exterior Calculus
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

# Get it from Subversion repository:
SVN_REPOSITORIES=	pydec
SVN_ROOT.pydec=  http://pydec.googlecode.com/svn/trunk
SVN_MODULE.pydec=	pydec

WRKSRC=			${WRKDIR}/pydec
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
