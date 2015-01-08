# $NetBSD: Makefile,v 1.2 2015/01/08 05:02:51 obache Exp $

DISTNAME=	atril-1.8.1
CATEGORIES=	print
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Simple multi-page document viewer for the MATE environment
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	atril-document.pc.in
PKGCONFIG_OVERRIDE+=	atril-view.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-icon-theme/buildlink3.mk"
.include "../../wip/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
