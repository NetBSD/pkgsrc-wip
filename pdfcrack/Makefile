# $NetBSD: Makefile,v 1.2 2015/03/10 23:33:26 leot1990 Exp $

DISTNAME=	pdfcrack-0.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfcrack/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://pdfcrack.sourceforge.net/
COMMENT=	Password Recovery Tool for PDF-files
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdfcrack ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pdfcrack.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
