# $NetBSD: Makefile,v 1.7 2012/09/29 16:59:05 asau Exp $

.include "../../wip/p5-HTML-Latex/Makefile.common"

CATEGORIES=		print

COMMENT=		HTML to LaTeX converter

DEPENDS+=		p5-HTML-Latex-${HTML2LATEX_VERSION}:../../wip/p5-HTML-Latex

DISTINFO_FILE=		${.CURDIR}/../../wip/p5-HTML-Latex/distinfo

REPLACE_PERL+=		html2latex

NO_BUILD=		YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2latex ${DESTDIR}${PREFIX}/bin/html2latex
	${INSTALL_MAN} ${WRKSRC}/html2latex.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
