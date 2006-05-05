# $NetBSD: Makefile,v 1.6 2006/05/05 22:24:03 jeremy-c-reed Exp $

.include "../../wip/p5-HTML-Latex/Makefile.common"

CATEGORIES=		print

COMMENT=		HTML to LaTeX converter

DEPENDS+=		p5-HTML-Latex-${HTML2LATEX_VERSION}:../../wip/p5-HTML-Latex

DISTINFO_FILE=		${.CURDIR}/../../wip/p5-HTML-Latex/distinfo

REPLACE_PERL+=		html2latex

NO_BUILD=		YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/html2latex ${PREFIX:Q}/bin/html2latex
	${INSTALL_MAN} ${WRKSRC:Q}/html2latex.1 ${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
