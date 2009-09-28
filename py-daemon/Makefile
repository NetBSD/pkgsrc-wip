# $NetBSD: Makefile,v 1.4 2009/09/28 12:33:33 jihbed Exp $
#

DISTNAME=	python-daemon-1.5.tar
PKGNAME=	${PYPKGPREFIX}-daemon-1.5.0
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/
EXTRACT_SUFX=	.gz#md5=61dc618978ffc30265326ad8a3a75248

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.8:../../wip/py-lockfile

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-daemon-1.5
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
