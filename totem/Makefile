# $NetBSD: Makefile,v 1.9 2004/02/24 17:11:57 jmmv Exp $
#

DISTNAME=	totem-0.95.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.hadess.net/files/software/totem/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.hadess.net/totem.php3
COMMENT=	Simple movie player for the Gnome desktop based on xine

DEPENDS+=		gnome2-dirs>=1.1:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=      YES

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

GCONF2_SCHEMAS=		totem-video-thumbnail.schemas
GCONF2_SCHEMAS+=	totem.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
