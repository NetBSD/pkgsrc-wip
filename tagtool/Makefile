# $NetBSD: Makefile,v 1.1.1.1 2007/02/19 19:34:33 guigui2 Exp $
#

DISTNAME=	tagtool-0.12.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tagtool/}

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://tagtool.sourceforge.net/
COMMENT=	GTK-based Ogg Vorbis and MP3 file tagger

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=             gmake intltool pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
