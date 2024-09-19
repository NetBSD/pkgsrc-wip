# $NetBSD: Makefile,v 1.9 2014/02/11 17:57:52 jihbed Exp $
#

DISTNAME=	dbus-explorer-0.5
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/dbus-explorer/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.ndesk.org/DBusExplorer
COMMENT=	GTK+ interface for viewing D-Bus service APIs written by C\#
#LICENSE=	# TODO

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config msgfmt gmake
USE_LANGUAGES=	# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
