# $NetBSD: Makefile,v 1.14 2012/09/24 17:14:32 asau Exp $
#

DISTNAME=		biopython-1.53
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		http://biopython.org/DIST/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://biopython.org/
COMMENT=		Python libraries for computational molecular biology
LICENSE=		Biopython

PKG_DESTDIR_SUPPORT=	none

PY_PATCHPLIST=		YES
PYDISTUTILSPKG=		YES
NO_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${PREFIX}/share/doc/biopython
.for f in README LICENSE CONTRIB
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/biopython
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.py \
		${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.fasta \
		${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.aln \
		${PREFIX}/share/examples/biopython
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/biopython/nmr
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/nmr/* \
		${PREFIX}/share/examples/biopython/nmr

.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
