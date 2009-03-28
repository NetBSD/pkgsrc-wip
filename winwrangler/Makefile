# $NetBSD: Makefile,v 1.1.1.1 2009/03/28 22:37:43 jihbed Exp $
#

DISTNAME=	winwrangler-0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/winwrangler/0.2/0.2.1/+download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://launchpad.net/winwrangler/
COMMENT=	WinWrangler desktop daemon to manipulations window managers

PKG_DESTDIR_SUPPORT= 	user-destdir
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/gtkhotkey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
