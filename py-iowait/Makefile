# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:45 asau Exp $
#

DISTNAME=	iowait-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/65588193/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpadlibrarian.net/65588193/
COMMENT=	Platform-independent module for I/O completion events
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
