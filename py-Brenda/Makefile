# $NetBSD: Makefile,v 1.3 2004/05/09 23:23:05 blef Exp $
#

DISTNAME=		PyBrenda-0.4.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		devel
MASTER_SITES=		http://www.snurgle.org/~pybrenda/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.snurgle.org/~pybrenda/
COMMENT=		Paralell computation system

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
NO_BUILD=		# defined

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

BRENDA_FILES=		Brenda.py einRpc.py myMath.py niftySocket.py
BRENDA_SHARE=		INSTALL LICENSE NEWS QuickStart README TODO examples/hello.py
BRENDA_DIR=		${PREFIX}/share/doc/${PKGNAME}

do-install:
	for a in ${BRENDA_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/${PYSITELIB}/$$a; \
	done
	${INSTALL_DATA_DIR} ${BRENDA_DIR}
	${INSTALL_DATA_DIR} ${BRENDA_DIR}/examples
	for a in ${BRENDA_SHARE}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${BRENDA_DIR}/$$a; \
	done

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
