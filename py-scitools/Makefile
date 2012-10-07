# $NetBSD: Makefile,v 1.7 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scitools-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S|scitools|SciTools|:Q}
PKGREVISION=	3
CATEGORIES=	science python
MASTER_SITES=	http://scitools.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/scitools/
COMMENT=	Python library for scientific computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw

USE_TOOLS+=	gzip
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

post-extract:
	gzip -d ${WRKSRC}/doc/man/man1/*.gz
	${MV} ${WRKSRC}/bin/pyreport ${WRKSRC}/bin/pyreport${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/scitools ${WRKSRC}/bin/scitools${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} ; ${PYTHONBIN} _test1.verify-test

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
