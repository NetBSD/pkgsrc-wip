# $NetBSD: Makefile,v 1.8 2004/04/15 11:03:04 jmmv Exp $
#

DISTNAME=	grip-3.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.nostatic.org/grip/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nostatic.org/grip/
COMMENT=	CD-player and CD-ripper for the GNOME desktop

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-id3

#.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
