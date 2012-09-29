# $NetBSD: Makefile,v 1.32 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=		grip-3.2.0
PKGREVISION=		8
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nostatic.org/grip/
COMMENT=		CD-player and CD-ripper for the Gnome desktop

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

BUILDLINK_FNAME_TRANSFORM.cdparanoia+=	-e s,/cdparanoia/,/,g

CONFIGURE_ARGS+=	--disable-id3

.include "../../audio/cdparanoia/buildlink3.mk"
#.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
