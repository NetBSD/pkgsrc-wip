# $NetBSD: Makefile,v 1.1.1.1 2003/03/24 22:42:50 marc Exp $
#

DISTNAME=	pyPgSQL-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
PYTHON_PATCH_SCRIPTS=	examples/basic.py
PYTHON_PATCH_SCRIPTS+=	examples/demo1a.py
PYTHON_PATCH_SCRIPTS+=	examples/demo1b.py
PYTHON_PATCH_SCRIPTS+=	examples/demo2a.py
PYTHON_PATCH_SCRIPTS+=	examples/demo2b.py

DOCDIR= ${PREFIX}/share/doc/pypgsql
EGDIR=  ${PREFIX}/share/examples/pypgsql
DOCS=	README README.html

post-install:
	${PYTHONBIN} -O ${LOCALBASE}/${PYLIB}/compileall.py \
		${LOCALBASE}/${PYSITELIB}/pyPgSQL
	${INSTALL_DATA_DIR} ${EGDIR}
.for file in ${PYTHON_PATCH_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}
.endfor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
