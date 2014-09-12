# $NetBSD: Makefile,v 1.4 2014/09/12 20:24:42 christtrekker Exp $
#

DISTNAME=	atque-1.1.2
CATEGORIES=	games editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=igniferroque/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://igniferroque.sourceforge.net/
COMMENT=	Marathon game map utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake gmake
USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers>=1.31
.include "../../devel/boost-headers/buildlink3.mk"
DEPENDS+=	boost-libs>=1.33:../../devel/boost-libs
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
