# $NetBSD: Makefile,v 1.2 2005/03/08 11:40:44 thomasklausner Exp $
#

DISTNAME=		biopython-1.30
WRKSRC=                 ${WRKDIR}/${DISTNAME}
CATEGORIES=		biology
MASTER_SITES=		http://biopython.org/files/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://biopython.org
COMMENT=		Python libraries for computational molecular biology

DEPENDS+=		py22-mxDateTime>=2.0.4:../../time/py-mxDateTime
DEPENDS+=		py22-Numeric>=23.3:../../math/py-Numeric

USE_BUILDLINK3=		yes
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


.include "../../lang/python22/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
