# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $
#

DISTNAME=	sushi-3.20.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/sushi/3.20/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/ThreePointOne/Features/FilePreviewing
COMMENT=	Quick File Previewing
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool perl pkg-config

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../print/evince3/buildlink3.mk"
.include "../../audio/libmusicbrainz/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../wip/clutter-gst/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../wip/gjs/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
