# $NetBSD: Makefile,v 1.1.1.1 2003/04/05 21:46:30 marc Exp $
#

DISTNAME=	pyPgSQL-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

WRKSRC=		${WRKDIR}/pypgsql
USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSION_REQD>=	20

post-install:
	${PYTHONBIN} -O ${LOCALBASE}/${PYLIB}/compileall.py \
		${LOCALBASE}/${PYSITELIB}/pyPgSQL

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
