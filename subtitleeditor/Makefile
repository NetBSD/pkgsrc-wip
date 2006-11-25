# $NetBSD: Makefile,v 1.3 2006/11/25 11:51:00 shattered Exp $
#

DISTNAME=		subtitleeditor-0.11.1
CATEGORIES=		multimedia
MASTER_SITES=		http://kitone.free.fr/subtitleeditor/files/

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://kitone.free.fr/subtitleeditor/
COMMENT=		GTK+2 tool to edit movie subtitles

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
