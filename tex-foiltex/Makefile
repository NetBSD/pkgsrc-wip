# $NetBSD: Makefile,v 1.3 2005/01/15 12:50:03 jmmv Exp $

DISTNAME=	# empty
PKGNAME=	tex-foiltex-2.1.4a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/foiltex/}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tex.ac.uk/tex-archive/help/Catalogue/entries/foiltex.html
COMMENT=	LaTeX2e class for overhead transparencies

DEPENDS+=	teTeX-bin>=1.0.2:../../print/teTeX-bin

NO_CONFIGURE=	YES
NO_BUILD=	YES

EVAL_PREFIX+=	LATEX_PREFIX=latex
EVAL_PREFIX+=	MKTEXLSR_PREFIX=mktexlsr
LATEX_PREFIX_DEFAULT=${LOCALBASE}
MKTEXLSR_PREFIX_DEFAULT=${LOCALBASE}

STYDIR=		${PREFIX}/share/texmf/tex/latex/foiltex

do-extract:
	for f in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$f ${WRKSRC}/$$f; \
	done
	cd ${WRKSRC} && ${LATEX_PREFIX}/bin/latex foiltex.ins > /dev/null

do-install:
	${INSTALL_DATA_DIR} ${STYDIR}
	cd ${WRKSRC} && for f in foils.* foil*.clo fltfonts.def; do \
		${INSTALL_DATA} $$f ${STYDIR}/$$f; \
	done

post-install:
	@${MKTEXLSR_PREFIX}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
