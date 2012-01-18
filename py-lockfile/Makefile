# $NetBSD: Makefile,v 1.2 2012/01/18 12:39:47 noud4 Exp $
#

DISTNAME=	lockfile-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://smontanaro.dyndns.org/python/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://smontanaro.dyndns.org/python/
COMMENT=	Platform-independent file locking module
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3

PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
