# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:29:36 jeremy-c-reed Exp $
#

DISTNAME=	lightdm-1.2.2
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm/1.2/1.2.2/+download/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/LightDM
COMMENT=	Light cross-desktop display manager
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

# Needed for launchpad
FETCH_USING=	curl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests	# PAM
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config
USE_LANGUAGES=	c c++
MAKE_ENV=	"LIBLIGHTDM_GOBJECT_CFLAGS=-I${BUILDLINK_PREFIX.glib2:Q}/include/glib/glib-2.0/"

PKGCONFIG_OVERRIDE+=	liblightdm-gobject/liblightdm-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	liblightdm-qt/liblightdm-qt-2.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/openpam/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=4.0
.include "../../x11/libxklavier/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
