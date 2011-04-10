# $NetBSD: Makefile,v 1.2 2011/04/10 15:13:12 ryo-on Exp $
#

DISTNAME=	libisofs-1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://libburnia-project.org/
COMMENT=	To create an ISO-9660 filesystem with extensions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libisofs-1.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
