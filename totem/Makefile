# $NetBSD: Makefile,v 1.5 2003/08/28 09:48:47 xtraeme Exp $
#

DISTNAME=	totem-0.95.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.hadess.net/files/software/totem/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.hadess.net/totem.php3
COMMENT=	Simple movie player for the Gnome desktop based on xine

DEPENDS+=		gnome2-dirs>=1.1:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=      YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

GCONF2_SCHEMAS=		totem-video-thumbnail.schemas
GCONF2_SCHEMAS+=	totem.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
