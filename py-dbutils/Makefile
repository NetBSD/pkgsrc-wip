# $NetBSD: Makefile,v 1.4 2014/01/25 10:38:17 thomasklausner Exp $

DISTNAME=	DBUtils-1.0
PKGNAME=	${PYPKGPREFIX}-dbutils-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.webwareforpython.org/downloads/DBUtils/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.webwareforpython.org/DBUtils
COMMENT=	Database connections for multi-threaded environments

DEPENDS+=	${PYPKGPREFIX}-postgresql>=4.0:../../databases/py-postgresql

USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-postgresql

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
