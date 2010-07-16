# $NetBSD: Makefile,v 1.1.1.1 2010/07/16 22:18:13 jihbed Exp $
#

DISTNAME=	magnitude-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://magnitude.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/magnitude/
COMMENT=	Python library for computing with numbers with units
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
