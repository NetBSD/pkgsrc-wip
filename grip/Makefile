# $NetBSD: Makefile,v 1.9 2004/04/25 00:10:32 thomasklausner Exp $
#

DISTNAME=	grip-3.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.nostatic.org/grip/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nostatic.org/grip/
COMMENT=	CD-player and CD-ripper for the GNOME desktop

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-id3

#.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
