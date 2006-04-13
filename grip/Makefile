# $NetBSD: Makefile,v 1.16 2006/04/13 18:18:14 jlamwww Exp $
#

DISTNAME=		grip-3.2.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grip/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://grip.sourceforge.net/
COMMENT=		CD-player and CD-ripper for the Gnome desktop

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake msgfmt
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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
