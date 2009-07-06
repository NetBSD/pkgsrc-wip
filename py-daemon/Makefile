# $NetBSD: Makefile,v 1.2 2009/07/06 19:34:55 jihbed Exp $
#

DISTNAME=	python-daemon-1.4.6.tar
PKGNAME=	${PYPKGPREFIX}-daemon-1.4.6
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.8:../../wip/py-lockfile

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-daemon-1.4.6
USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
