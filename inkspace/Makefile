# $NetBSD: Makefile,v 1.1.1.1 2004/04/12 22:00:27 jeremy-c-reed Exp $
#

DISTNAME=		inkscape-0.38.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=inkscape/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.inkscape.org/
COMMENT=		Scalable Vector Graphics (SVG) editor

.if ! exists (/usr/bin/iconv)
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv
.endif

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
