# $NetBSD: Makefile,v 1.1 2005/03/13 13:10:39 martijnb Exp $
#

DISTNAME=	easytag-1.99.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martijn.van.buul@gmail.com
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK2 interface

BUILD_USES_MSGFMT=      yes     # xgettext, really

GNU_CONFIGURE=          yes
USE_DIRS+=              xdg-1.1
USE_GNU_TOOLS+=         make
USE_X11=                yes
USE_BUILDLINK3=         yes
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
