# $NetBSD: Makefile,v 1.7 2005/09/06 12:56:13 leonardschmidt Exp $
#

DISTNAME=	easytag-1.99.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martijn.van.buul@gmail.com
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	GTK2 Tag editor for MP3, Ogg Vorbis files, and others

BUILD_USES_MSGFMT=      yes     # xgettext, really

GNU_CONFIGURE=          yes
USE_DIRS+=              xdg-1.1
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes

.include "options.mk"

.include "../../audio/id3lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
