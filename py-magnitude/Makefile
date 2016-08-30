# $NetBSD: Makefile,v 1.4 2015/01/10 20:21:14 thomasklausner Exp $

DISTNAME=	magnitude-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://github.com/downloads/juanre/magnitude/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/juanre/magnitude/wiki
COMMENT=	Python library for computing with numbers with units
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,mgload.py,mgload${PYVERSSUFFIX},g'
SUBST_SED.paths+=	-e 's,tlslite/scripts/tls.py,tls${PYVERSSUFFIX},g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

DOCDIR=	${PREFIX}/share/doc/py-magnitude

post-extract:
	cd ${WRKSRC} && ${MV} mgload.py mgload${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${PYTHONBION} test/test-mg.py

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
