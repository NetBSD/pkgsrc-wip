# $NetBSD: Makefile,v 1.9 2010/07/12 19:04:47 jihbed Exp $
#

DISTNAME=	spade-2.0rc4
CATEGORIES=	devel python
MASTER_SITES=	http://spade2.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/spade2/
COMMENT=	SPADE is an agent platform based on the XMPP/Jabber technology
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-psyco>=1.6:../../lang/py-psyco
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.13:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-event>=0.3:../../wip/py-event
DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.04:../../wip/py-gmpy
DEPENDS+=	jython>=2.5.1:../../wip/jython

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

WRKSRC=	${WRKDIR}/spade

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,tlslite/scripts/tlsdb.py,tlsdb${PYVERSSUFFIX},g'
SUBST_SED.paths+=	-e 's,tlslite/scripts/tls.py,tls${PYVERSSUFFIX},g'
SUBST_SED.paths+=	-e 's,/usr/share/doc/spade,${PREFIX}/share/doc/spade,g'
SUBST_FILES.paths+=	setup.py runspade.py
SUBST_MESSAGE.paths=	Fixing header search paths.

REPLACE_PYTHON+=	tls${PYVERSSUFFIX} tlsdb${PYVERSSUFFIX}

post-extract:
	${CP} ${FILESDIR}/tls.py ${WRKSRC}/tls${PYVERSSUFFIX}
	${CP} ${FILESDIR}/tlsdb.py ${WRKSRC}/tlsdb${PYVERSSUFFIX}

TEST_ENV+=	PYTHONPATH=${WRKSRC}/examples/unittests
do-test:
	${RUN} cd ${WRKSRC}/examples/unittests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} unittests.py

pre-configure:
	cd ${WRKSRC} && ${PYTHONBIN} configure.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
