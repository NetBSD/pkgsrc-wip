# $NetBSD: Makefile,v 1.3 2005/09/05 19:49:14 rillig Exp $

.include "../../wip/p5-HTML-Latex/Makefile.common"

CATEGORIES=		print

COMMENT=		HTML to LaTeX converter

DEPENDS+=		p5-HTML-Latex-${HTML2LATEX_VERSION}:../../wip/p5-HTML-Latex

DISTINFO_FILE=		${.CURDIR}/../../wip/p5-HTML-Latex/distinfo

REPLACE_PERL=		html2latex

NO_BUILD=		YES

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/html2latex ${PREFIX}/bin/html2latex
		${INSTALL_MAN} ${WRKSRC}/html2latex.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
