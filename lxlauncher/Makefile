# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:28:15 jeremy-c-reed Exp $

DISTNAME=	lxlauncher-0.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.lxde.org/en/LXLauncher
COMMENT=	Program launcher for small screens

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

.include "../../wip/menu-cache/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
