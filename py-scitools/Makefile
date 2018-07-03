# $NetBSD: Makefile,v 1.15 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	scitools-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S|scitools|SciTools|:Q}
PKGREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=hplgit/}
GITHUB_PROJECT=	scitools
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hplgit/scitools
COMMENT=	Python library for scientific computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-gtk>=1.1.1:../../graphics/py-matplotlib-gtk2

USE_TOOLS+=	gzip
USE_LANGUAGES=	# none

PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2 via py-matplotlib-gtk2

post-extract:
	gzip -d ${WRKSRC}/doc/man/man1/*.gz
	${MV} ${WRKSRC}/bin/scitools ${WRKSRC}/bin/scitools${PYVERSSUFFIX}

#optional dependency:
#DEPENDS+=			${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
#PYTHON_VERSIONED_DEPENDENCIES=	Pmw X
#.include "../../lang/python/versioned_dependencies.mk"
#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 35 35 34 34 # py-Numeric
#.include "../../math/py-Numeric/buildlink3.mk"
#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 35 35 34 34 # py-numarray
#.include "../../math/py-numarray/buildlink3.mk"
#.include "../../graphics/vtk/buildlink3.mk"

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
