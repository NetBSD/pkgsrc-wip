# $NetBSD: Makefile,v 1.3 2004/04/25 06:30:59 blef Exp $
#

DISTNAME=		grisbi-0.4.2
CATEGORIES=		finance
MASTER_SITES=		http://www.grisbi.org/download/packages/0.4.2/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.grisbi.org/
COMMENT=		Personal Finance Manager under Gnome/GTK

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../print/gnome-print/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
