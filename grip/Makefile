# $NetBSD: Makefile,v 1.34 2013/01/21 01:53:59 othyro Exp $
#

DISTNAME=	grip-3.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nostatic.org/grip/
COMMENT=	CD-player and CD-ripper for the Gnome desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt intltool msgmerge pkg-config xgettext
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

BUILDLINK_FNAME_TRANSFORM.cdparanoia+=	-e s,/cdparanoia/,/,g

CONFIGURE_ARGS+=	--disable-id3


.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
#.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
