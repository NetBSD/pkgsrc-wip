# $NetBSD: Makefile,v 1.1 2014/02/03 21:25:31 jihbed Exp $

DISTNAME=	sleekxmpp-1.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat  python
MASTER_SITES=	https://pypi.python.org/packages/source/s/sleekxmpp/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/fritzy/SleekXMPP
COMMENT=	SleekXMPP is an elegant Python library for XMPP
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dns>=1.11.1:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testall.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
