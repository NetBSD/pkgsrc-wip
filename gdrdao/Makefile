# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:22 thomasklausner Exp $
#

DISTNAME=	gdrdao-0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gdrdao/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gdrdao.sourceforge.net/
COMMENT=	GTK-based GUI frontend for cdrdao

DEPENDS+=       cdrdao-[0-9]*:../../sysutils/cdrdao

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_GMAKE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
