# $NetBSD: Makefile,v 1.1.1.1 2004/07/12 16:05:54 ianzag Exp $
#

DISTNAME=		scribus-1.1.7
CATEGORIES=		kde textproc
MASTER_SITES=	http://ahnews.music.salford.ac.uk/scribus/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Scribus is a desktop page layout program

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
