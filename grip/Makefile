# $NetBSD: Makefile,v 1.14 2005/08/03 18:38:57 jmmv Exp $
#

DISTNAME=		grip-3.2.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grip/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://grip.sourceforge.net/
COMMENT=		CD-player and CD-ripper for the Gnome desktop

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM.cdparanoia+=    -e s,/cdparanoia/,/,g

CONFIGURE_ARGS+=	--disable-id3

.include "../../audio/cdparanoia/buildlink3.mk"
#.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
