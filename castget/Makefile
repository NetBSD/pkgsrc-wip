# $NetBSD: Makefile,v 1.1.1.1 2007/04/25 19:52:59 guigui2 Exp $
#

DISTNAME=	castget-0.9.6
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/castget/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://savannah.nongnu.org/download/castget/
COMMENT=	Command-line RSS enclosures dowloader

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=             gmake intltool pkg-config

.include "../../www/curl/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
