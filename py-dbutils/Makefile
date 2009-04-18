# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 23:35:52 jihbed Exp $
#

DISTNAME=	DBUtils-1.0
PKGNAME=		${PYPKGPREFIX}-dbutils-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.webwareforpython.org/downloads/DBUtils/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.webwareforpython.org/DBUtils
COMMENT=	Database connections for multi-threaded environments

DEPENDS+=	${PYPKGPREFIX}-postgresql>=4.0:../../databases/py-postgresql

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
