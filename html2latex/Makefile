# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 21:25:28 jeremy-c-reed Exp $

DISTNAME=		html2latex-1.0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=html2latex/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://html2latex.sourceforge.net/
COMMENT=		HTML to LaTeX converter

DEPENDS+		p5-HTML-Latex-[0-9]*:../../wip/p5-HTML-Latex

REPLACE_PERL=		html2latex

NO_CONFIGURE=		YES
NO_BUILD=		YES

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/html2latex ${PREFIX}/bin/html2latex
		${INSTALL_MAN} ${WRKSRC}/html2latex.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
