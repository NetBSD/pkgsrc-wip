# $NetBSD: Makefile,v 1.1.1.1 2004/07/15 16:06:00 ianzag Exp $
#

DISTNAME=		gwenview-1.1.3
CATEGORIES=		kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://gwenview.sourceforge.net/
COMMENT=		Gwenview is an image viewer for KDE whose aims are ease of use and speed

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-kipi

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
