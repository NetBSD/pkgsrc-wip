# $NetBSD: Makefile,v 1.1.1.1 2011/01/21 15:03:20 ryo-on Exp $
#

DISTNAME=	pdfgrep-1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfgrep/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pdfgrep.sourceforge.net/
COMMENT=	Pdfgrep is a tool to search text in PDF files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
