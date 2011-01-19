# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 14:38:34 jihbed Exp $
#

DISTNAME=	scitools-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://scitools.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/scitools/
COMMENT=	Python library for scientific computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gzip
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

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
.include "../../x11/py-Pmw/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
