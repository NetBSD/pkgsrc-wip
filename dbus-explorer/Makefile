# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:31 asau Exp $
#

DISTNAME=	dbus-explorer-0.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/dbus-explorer/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://neteril.org/projects/dbus-explorer/
COMMENT=	GTK+ interface for viewing D-Bus service APIs written by C\#
#LICENSE=	# TODO

GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config msgfmt gmake
USE_LANGUAGES=	# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
