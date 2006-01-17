# $NetBSD: Makefile,v 1.4 2006/01/17 10:20:00 rillig Exp $

.include "../../wip/p5-HTML-Latex/Makefile.common"

CATEGORIES=		print

COMMENT=		HTML to LaTeX converter

DEPENDS+=		p5-HTML-Latex-${HTML2LATEX_VERSION}:../../wip/p5-HTML-Latex

DISTINFO_FILE=		${.CURDIR}/../../wip/p5-HTML-Latex/distinfo

REPLACE_PERL+=		html2latex

NO_BUILD=		YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/html2latex ${PREFIX:Q}/bin/html2latex
	${INSTALL_MAN} ${WRKSRC:Q}/html2latex.1 ${PREFIX:Q}/man/man1

.include "../../mk/bsd.pkg.mk"
