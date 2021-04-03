# $NetBSD: Makefile,v 1.1 2014/03/19 22:03:31 jihbed Exp $

DISTNAME=	pywebsocket-0.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlearchive/}
GITHUB_PROJECT=	pywebsocket
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pywebsocket/
COMMENT=	WebSocket server and extension for Apache HTTP Server for testing
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pywebsocket-0.7.9/src

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_all.py;

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
