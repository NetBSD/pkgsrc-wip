# $NetBSD: Makefile,v 1.1.1.1 2009/06/26 22:37:42 jihbed Exp $
#

DISTNAME=	python-daemon-1.4.5.tar
PKGNAME=	${PYPKGPREFIX}-daemon-1.4.5
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.8:../../wip/py-lockfile

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-daemon-1.4.5
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
