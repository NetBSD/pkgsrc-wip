# $NetBSD: Makefile,v 1.13 2009/12/20 11:25:39 pallegra Exp $
#

DISTNAME=	awesome-3.4.2
CATEGORIES=	x11 wm
MASTER_SITES=	http://awesome.naquadah.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://awesome.naquadah.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	awesome<3.0

USE_TOOLS+=	bash
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	c c++

REPLACE_BASH+=	build-utils/gperf.sh

EGDIR=		${PREFIX}/share/examples/awesome
CONF_FILES=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/xdg/awesome/rc.lua

BUILD_DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=	asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml


.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
