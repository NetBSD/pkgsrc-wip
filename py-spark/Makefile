# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 02:21:08 mjasm Exp $
#

DISTNAME=		spark-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://pages.cpsc.ucalgary.ca/~aycock/spark/
COMMENT=		Scanning, Parsing, and Rewriting Kit for Python

USE_BUILDLINK2= YES
PYTHON_VERSION_REQD=    22pth

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark;
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/doc;
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/auto
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/paper
	${INSTALL_DATA_DIR} ${PREFIX}/share/py-spark/examples/python
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/py-spark/doc
	${INSTALL_DATA} ${WRKSRC}/examples/auto/* ${PREFIX}/share/py-spark/examples/auto
	${INSTALL_DATA} ${WRKSRC}/examples/paper/* ${PREFIX}/share/py-spark/examples/paper
	${INSTALL_DATA} ${WRKSRC}/examples/python/* ${PREFIX}/share/py-spark/examples/python
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${PREFIX}/${PYSITELIB}/
	${LN} ${PREFIX}/${PYSITELIB}/spark.py ${PREFIX}/${PYSITELIB}/generic.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
