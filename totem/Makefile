# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 10:29:56 xtraeme Exp $
#

DISTNAME=	totem-0.95.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.hadess.net/files/software/totem/

MAINTAINER=	jrp@hispabsd.org
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

.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
