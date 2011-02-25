# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	cryptoIDlib-0.3.3
PKGNAME=	${PYPKGPREFIX}-cryptoidlib-0.3.3
CATEGORIES=	security python
MASTER_SITES=	http://www.trevp.com/cryptoID/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.trevp.com/cryptoID/
COMMENT=	CryptoIDlib is a python library for working with cryptoID certChains
#LICENSE=	# TODO: (see mk/license.mk)


DEPENDS+=	${PYPKGPREFIX}-amkCrypto>=2.0.1:../../security/py-amkCrypto
DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.13:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-tlslite>=0.3.8:../../security/py-tlslite
DEPENDS+=	jython>=2.5.1:../../wip/jython
DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.04:../../wip/py-gmpy

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24 23
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

REPLACE_PYTHON+=	scripts/cryptoID.py scripts/cryptoIDcli.py scripts/cryptoIDsrv.py

DOCDIR=		${PREFIX}/share/doc/py-cryptoidlib

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
