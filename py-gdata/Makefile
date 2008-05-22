# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:47 tnn2 Exp $
# Note: patch-aa fixes a known bug, so should be removed
# with the next release.

DISTNAME=	gdata.py-1.0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.py//}
CATEGORIES=	www python
MASTER_SITES=	http://gdata-python-client.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/gdata-python-client/
COMMENT=	Google Data API Python client library

DEPENDS+=	${PYPKGPREFIX}-elementtree-[0-9]*:../../textproc/py-elementtree

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

# Install docs and samples manually
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${PREFIX}/share/doc/${PKGBASE}
	for i in base blogger calendar docs mashups spreadsheets; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/samples/$$i && \
		${INSTALL_DATA} ${WRKSRC}/samples/$$i/* ${PREFIX}/share/doc/${PKGBASE}/samples/$$i; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
