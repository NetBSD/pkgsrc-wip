# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 17:34:02 jihbed Exp $
#

DISTNAME=	libowl-av-0.1
CATEGORIES=	audio
MASTER_SITES=	http://labs.o-hand.com/sources/libowl-av/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://labs.o-hand.com/av-widget-library/
COMMENT=	AV widget library
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libowl-av.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.1
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.1
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
