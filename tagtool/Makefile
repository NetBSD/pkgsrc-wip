# $NetBSD: Makefile,v 1.5 2007/09/21 13:06:55 thomasklausner Exp $
#

DISTNAME=	tagtool-0.12.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tagtool/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://pwp.netcabo.pt/paol/tagtool/
COMMENT=	GTK-based Ogg Vorbis and MP3 file tagger

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=             gmake intltool pkg-config
USE_DIRS+=              xdg-1.4

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
