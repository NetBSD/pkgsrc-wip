# $NetBSD: Makefile,v 1.16 2013/12/02 09:46:01 jihbed Exp $

DISTNAME=	biopython-1.63b
PKGNAME=	$(PYPKGPREFIX)-$(DISTNAME)
CATEGORIES=	biology
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	Biopython

PYTHON_VERSIONS_INCLUDE_3X=yes
PYDISTUTILSPKG=		YES

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/*.pdf ${DESTDIR}${PREFIX}/share/doc/biopython
.for f in README LICENSE CONTRIB
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/biopython
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.py \
		${DESTDIR}${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.fasta \
		${DESTDIR}${PREFIX}/share/examples/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.aln \
		${DESTDIR}${PREFIX}/share/examples/biopython
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/biopython/nmr
	${INSTALL_DATA} ${WRKSRC}/Doc/examples/nmr/* \
		${DESTDIR}${PREFIX}/share/examples/biopython/nmr

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.5:../../print/py-reportlab
.include "../../mk/bsd.pkg.mk"
