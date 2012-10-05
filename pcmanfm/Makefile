# $NetBSD: Makefile,v 1.2 2012/10/05 08:46:08 asau Exp $
#

DISTNAME=	pcmanfm-0.9.10
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

.include "../../wip/menu-cache/buildlink3.mk"

.include "../../wip/libfm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
