# $NetBSD: Makefile,v 1.5 2012/10/07 14:07:06 asau Exp $
#

DISTNAME=		r8s1.7.dist
PKGNAME=		r8s-1.70
CATEGORIES=		biology
MASTER_SITES=		http://loco.biosci.arizona.edu/r8s/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://loco.biosci.arizona.edu/r8s/
COMMENT=		Estimate rates of molecular evolution

WRKSRC=			${WRKDIR}/dist/src
BUILD_TARGET=		r8s

BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/r8s
EXAMPLESDIR=		${PREFIX}/share/examples/r8s

DOCS+=			r8s1.7.manual.pdf
EXAMPLES+=		SAMPLE_1.7
EXAMPLES+=		SAMPLE_CONSTRAINTS
EXAMPLES+=		SAMPLE_CROSSVAL
EXAMPLES+=		SAMPLE_FLU
EXAMPLES+=		SAMPLE_LOCAL_CLOCK
EXAMPLES+=		SAMPLE_SIMPLE
EXAMPLES+=		SAMPLE_SUPERTREE

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/r8s ${DESTDIR}${BINDIR}/r8s
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../doc/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/../sample/${f} ${DESTDIR}${EXAMPLESDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
