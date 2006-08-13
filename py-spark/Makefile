# $NetBSD: Makefile,v 1.6 2006/08/13 23:33:25 thomasklausner Exp $
#

DISTNAME=		spark-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pages.cpsc.ucalgary.ca/~aycock/spark/
COMMENT=		Scanning, Parsing, and Rewriting Kit for Python

NO_BUILD=	YES
PY_PATCHPLIST=	YES
PYTHON_VERSIONS_ACCEPTED=    23 22

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/auto
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/paper
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/python
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/py-spark/doc
	${INSTALL_DATA} ${WRKSRC}/examples/auto/* ${PREFIX}/share/py-spark/examples/auto
	${INSTALL_DATA} ${WRKSRC}/examples/paper/* ${PREFIX}/share/py-spark/examples/paper
	${INSTALL_DATA} ${WRKSRC}/examples/python/* ${PREFIX}/share/py-spark/examples/python
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${PREFIX}/${PYSITELIB}
#	${LN} ${PREFIX}/${PYSITELIB}/spark.py ${PREFIX}/${PYSITELIB}/generic.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
