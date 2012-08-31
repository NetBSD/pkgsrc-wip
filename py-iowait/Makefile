# $NetBSD: Makefile,v 1.1 2012/08/31 18:11:04 jihbed Exp $
#

DISTNAME=	iowait-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/65588193/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpadlibrarian.net/65588193/
COMMENT=	Platform-independent module for I/O completion events
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
