# $NetBSD: Makefile,v 1.1.1.1 2004/07/12 14:45:57 ianzag Exp $
#

DISTNAME=		krusader-1.40-beta2
CATEGORIES=		kde x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=krusader/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://krusader.sourceforge.net/
COMMENT=		Krusader is an advanced twin-panel (commander-style) file-manager for KDE 3.x

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
