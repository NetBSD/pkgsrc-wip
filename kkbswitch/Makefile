# $NetBSD: Makefile,v 1.1.1.1 2004/06/24 14:59:29 ianzag Exp $
#

DISTNAME=		kkbswitch-1.4.1
CATEGORIES=		kde x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kkbswitch/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kkbswitch.sourceforge.net/
COMMENT=		Keyboard layout indicator for KDE 2 or 3

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
