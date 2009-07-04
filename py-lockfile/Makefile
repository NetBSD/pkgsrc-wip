# $NetBSD: Makefile,v 1.1.1.1 2009/07/04 22:38:25 jihbed Exp $
#

DISTNAME=	lockfile-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://smontanaro.dyndns.org/python/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://smontanaro.dyndns.org/python/
COMMENT=	Platform-independent file locking module
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-sqlite3-0:../../databases/py-sqlite3

PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
