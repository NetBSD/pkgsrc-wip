# $NetBSD: Makefile,v 1.3 2009/09/23 09:20:41 jihbed Exp $
#

DISTNAME=	python-daemon-1.4.8.tar
PKGNAME=	${PYPKGPREFIX}-daemon-1.4.8
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/
EXTRACT_SUFX=	.gz#md5=a8af55f85ea7675fd49ef6d2be026a75

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.8:../../wip/py-lockfile

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-daemon-1.4.8
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
