# $NetBSD: Makefile,v 1.4 2005/11/09 09:23:05 jtonio Exp $

DISTNAME=	# empty
PKGNAME=	tex-foiltex-2.1.4a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/foiltex/}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tex.ac.uk/tex-archive/help/Catalogue/entries/foiltex.html
COMMENT=	LaTeX2e class for overhead transparencies

NO_CONFIGURE=	YES
NO_BUILD=	YES

EVAL_PREFIX+=	LATEX_PREFIX=latex
EVAL_PREFIX+=	MKTEXLSR_PREFIX=mktexlsr
LATEX_PREFIX_DEFAULT=${LOCALBASE}
MKTEXLSR_PREFIX_DEFAULT=${LOCALBASE}

STYDIR=		${PKG_LOCALTEXMFPREFIX}/tex/latex/foiltex

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

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
