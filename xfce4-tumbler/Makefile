# $NetBSD: Makefile,v 1.1.1.1 2012/02/19 20:10:18 guigui2 Exp $
#

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	tumbler-0.1.23
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	http://archive.xfce.org/src/xfce/tumbler/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://www.xfce.org/
COMMENT=	D-Bus thumbnailing service

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	tumbler/tumbler-1.pc.in

.include "../../devel/libgsf/buildlink3.mk"
.include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
