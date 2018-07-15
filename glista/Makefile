# $NetBSD$
#

DISTNAME=	glista-0.3
CATEGORIES=	time gnome
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/glista/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://prematureoptimization.org/glista/
COMMENT=	Simple task list management utility

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+= 	xdg-1.4
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
