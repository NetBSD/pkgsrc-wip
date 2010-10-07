# $NetBSD: Makefile,v 1.9 2010/10/07 00:37:20 jihbed Exp $
#

DISTNAME=	spark-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=	http://pages.cpsc.ucalgary.ca/~aycock/spark/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pages.cpsc.ucalgary.ca/~aycock/spark/
COMMENT=	Scanning, Parsing, and Rewriting Kit for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax
NO_BUILD=	YES

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

INSTALLATION_DIRS=	share/py-spark ${PYSITELIB}

do-install:
	cd ${WRKSRC}/doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/py-spark/doc
	cd ${WRKSRC}/examples  && pax -rw -pp . ${DESTDIR}${PREFIX}/share/py-spark/examples
	${INSTALL_SCRIPT} ${WRKSRC}/spark.py ${DESTDIR}${PREFIX}/${PYSITELIB}
#	${LN} ${PREFIX}/${PYSITELIB}/spark.py ${PREFIX}/${PYSITELIB}/generic.py


.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
