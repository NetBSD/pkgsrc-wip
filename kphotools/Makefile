# $NetBSD: Makefile,v 1.1.1.1 2004/07/15 15:11:22 ianzag Exp $
#

DISTNAME=		kphotools-0.2.1
CATEGORIES=		kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kphotools.sourceforge.net/
COMMENT=		KDE app which helps you creating fast online photo galleries in HTML

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
