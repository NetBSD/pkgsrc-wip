# $NetBSD: Makefile,v 1.4 2005/05/15 02:52:05 rillig Exp $
#

DISTNAME=		biopython-1.30
CATEGORIES=		biology
MASTER_SITES=		http://biopython.org/files/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://biopython.org/
COMMENT=		Python libraries for computational molecular biology

DEPENDS+=		py22-mxDateTime>=2.0.4:../../time/py-mxDateTime
DEPENDS+=		py22-Numeric>=23.3:../../math/py-Numeric

NO_CONFIGURE=		yes

LICENSE=		non-commercial-use
PYTHON=			python2.2

do-build:
	cd ${WRKSRC} && \
	${PYTHON} setup.py build

do-install:
	cd ${WRKSRC} && \
	${PYTHON} setup.py install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${PREFIX}/share/doc/biopython
.for doc in README LICENSE CONTRIB
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/biopython
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

.include "../../lang/python22/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
