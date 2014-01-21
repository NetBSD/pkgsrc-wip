# $NetBSD: Makefile,v 1.12 2014/01/21 10:55:39 thomasklausner Exp $

DISTNAME=	scitools-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S|scitools|SciTools|:Q}
PKGREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	http://scitools.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/scitools/
COMMENT=	Python library for scientific computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-gtk2>=1.1.1:../../graphics/py-matplotlib-gtk2

USE_TOOLS+=	gzip
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

post-extract:
	gzip -d ${WRKSRC}/doc/man/man1/*.gz
	${MV} ${WRKSRC}/bin/scitools ${WRKSRC}/bin/scitools${PYVERSSUFFIX}

#optional dependency:
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
#PYTHON_VERSIONED_DEPENDENCIES=	Pmw X
#.include "../../lang/python/versioned_dependencies.mk"
#.include "../../math/py-Numeric/buildlink3.mk"
#.include "../../math/py-numarray/buildlink3.mk"
#.include "../../graphics/vtk/buildlink3.mk"

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
