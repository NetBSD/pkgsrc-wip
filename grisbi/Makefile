# $NetBSD: Makefile,v 1.2 2004/01/25 02:23:01 grantbeattie Exp $
#

DISTNAME=		grisbi-0.4.2
CATEGORIES=		finance
MASTER_SITES=		http://www.grisbi.org/download/packages/0.4.2/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.grisbi.org/
COMMENT=		Personal Finance Manager under Gnome/GTK

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../print/gnome-print/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
