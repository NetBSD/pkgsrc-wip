# $NetBSD: Makefile,v 1.8 2012/10/11 14:25:00 jihbed Exp $
#

DISTNAME=	scitools-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S|scitools|SciTools|:Q}
PKGREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	http://scitools.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/scitools/
COMMENT=	Python library for scientific computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-tk>=1.1.1:../../graphics/py-matplotlib-tk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gzip
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

post-extract:
	gzip -d ${WRKSRC}/doc/man/man1/*.gz
	${MV} ${WRKSRC}/bin/scitools ${WRKSRC}/bin/scitools${PYVERSSUFFIX}

#optional dependency:
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
#DEPENDS+=	${PYPKGPREFIX}-X>=0.9:../../textproc/py-X
#DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw
#.include "../../math/py-Numeric/buildlink3.mk"
#.include "../../math/py-numarray/buildlink3.mk"
#.include "../../graphics/vtk/buildlink3.mk"

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
