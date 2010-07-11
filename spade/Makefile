# $NetBSD: Makefile,v 1.3 2010/07/11 14:38:23 jihbed Exp $
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
DEPENDS+=	${PYPKGPREFIX}-event>=0.3:../../wip/py-event
DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.04:../../wip/py-gmpy
DEPENDS+=	jython>=2.5.1:../../wip/jython

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes

WRKSRC=	${WRKDIR}/spade

TEST_ENV+=	PYTHONPATH=${WRKSRC}/examples/unittests
do-test:
	${RUN} cd ${WRKSRC}/examples/unittests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} unittests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
