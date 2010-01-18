# $NetBSD: Makefile,v 1.20 2010/01/18 09:38:28 thomasklausner Exp $
#

DISTNAME=		monkey-bubble-0.4.0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://home.gna.org/monkeybubble/downloads/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://home.gna.org/monkeybubble/
COMMENT=		Bust'A'Move clone written for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
