# $NetBSD: Makefile,v 1.3 2012/10/07 11:54:20 asau Exp $
#

DISTNAME=	DBUtils-1.0
PKGNAME=		${PYPKGPREFIX}-dbutils-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.webwareforpython.org/downloads/DBUtils/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.webwareforpython.org/DBUtils
COMMENT=	Database connections for multi-threaded environments

DEPENDS+=	${PYPKGPREFIX}-postgresql>=4.0:../../databases/py-postgresql

USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
