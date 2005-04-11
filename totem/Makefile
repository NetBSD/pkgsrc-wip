# $NetBSD: Makefile,v 1.13 2005/04/11 21:16:04 tvierling Exp $
#

DISTNAME=	totem-0.99.9
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://www.hadess.net/files/software/totem/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hadess.net/totem.php3
COMMENT=	Movie player for the GNOME desktop based on xine

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GCONF2_SCHEMAS=		totem.schemas
GCONF2_SCHEMAS+=	totem-video-thumbnail.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
