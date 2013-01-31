# $NetBSD: Makefile,v 1.4 2013/01/31 03:35:01 jeremy-c-reed Exp $
#

DISTNAME=	pcmanfm-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	Extremly fast and lightweight file manager

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		intltool pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../sysutils/menu-cache/buildlink3.mk"

.include "../../wip/libfm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
