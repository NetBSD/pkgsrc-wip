# $NetBSD: Makefile,v 1.3 2005/04/16 14:49:00 thomasklausner Exp $
#

DISTNAME=	easytag-1.99.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martijn.van.buul@gmail.com
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	GTK2 Tag editor for MP3, Ogg Vorbis files, and others

BUILD_USES_MSGFMT=      yes     # xgettext, really

GNU_CONFIGURE=          yes
USE_DIRS+=              xdg-1.1
USE_X11=                yes
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
