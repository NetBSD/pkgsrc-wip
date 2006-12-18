# $NetBSD: Makefile,v 1.7 2006/12/18 01:37:32 thomasklausner Exp $
#

DISTNAME=		grisbi-0.5.5
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grisbi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.grisbi.org/
COMMENT=		Personal Finance Manager under Gnome/GTK

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
