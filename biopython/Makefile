# $NetBSD: Makefile,v 1.6 2005/09/29 13:47:28 thomasklausner Exp $
#

DISTNAME=		biopython-1.40b
WRKSRC=                 ${WRKDIR}/${DISTNAME}
CATEGORIES=		biology
MASTER_SITES=		http://biopython.org/files/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://biopython.org
COMMENT=		Python libraries for computational molecular biology

LICENSE=		no-commercial-use

PY_PATCHPLIST=		YES
PYDISTUTILSPKG=         YES
NO_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/biopython
.for DOC in *.txt
	${INSTALL_DATA} ${WRKSRC}/Doc/${DOC} ${PREFIX}/share/doc/biopython
.endfor
.for DOC in README LICENSE CONTRIB
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/biopython
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/biopython
.for EXAPY in *.py
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/${EXAPY} \
		${PREFIX}/share/examples/biopython
.endfor
.for EXAFS in *.fasta
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/${EXAFS} \
		${PREFIX}/share/examples/biopython
.endfor
.for EXAALN in *.aln
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/${EXAALN} \
		${PREFIX}/share/examples/biopython
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/biopython/nmr
.for NMR in *
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/nmr/${NMR} \
		${PREFIX}/share/examples/biopython/nmr
.endfor

.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
