# $NetBSD: Makefile,v 1.12 2012/10/06 17:13:24 asau Exp $
#

DISTNAME=	PyBrenda041-tar
PKGNAME=	${PYPKGPREFIX}-Brenda-0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://xml.coverpages.org/
EXTRACT_SUFX=	.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.python.org/moin/PyBrenda
COMMENT=		Parallel computation system

WRKSRC=	${WRKDIR}/PyBrenda-0.4.1

PY_PATCHPLIST=		yes
NO_BUILD=		yes

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

BRENDA_FILES=		Brenda.py einRpc.py myMath.py niftySocket.py
BRENDA_SHARE=		INSTALL LICENSE NEWS QuickStart README TODO examples/hello.py
BRENDA_DIR=		${PREFIX}/share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PYSITELIB}
	for a in ${BRENDA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/${PYSITELIB}/$$a; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${BRENDA_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${BRENDA_DIR}/examples
	for a in ${BRENDA_SHARE}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${BRENDA_DIR}/$$a; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
