# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:26:08 jihbed Exp $
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

DOCDIR=	${PREFIX}/share/doc/py-magnitude

do-test:
	cd ${WRKSRC} && ${PYTHONBION} test/test-mg.py

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
