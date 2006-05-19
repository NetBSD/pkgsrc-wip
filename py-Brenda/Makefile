# $NetBSD: Makefile,v 1.9 2006/05/19 16:51:30 ykomatsu Exp $
#

DISTNAME=		PyBrenda-0.4.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		devel
MASTER_SITES=		http://www.snurgle.org/~pybrenda/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.python.org/moin/PyBrenda
COMMENT=		Parallel computation system

PY_PATCHPLIST=		yes
NO_BUILD=		yes

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}

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
