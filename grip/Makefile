# $NetBSD: Makefile,v 1.2 2003/05/28 02:11:30 xtraeme Exp $
#

DISTNAME=	grip-3.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.nostatic.org/grip/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.nostatic.org/grip/
COMMENT=	cd-player and cd-ripper for the Gnome desktop

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--disable-id3

#.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
