# $NetBSD: Makefile,v 1.1.1.1 2004/07/15 14:31:38 ianzag Exp $
#

DISTNAME=		kphotobook-0.0.6
CATEGORIES=		kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotobook/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kphotobook.sourceforge.net/
COMMENT=		Powerful, easy to use, intuitive and fast KDE application to manage and organize your photos

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
