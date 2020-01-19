# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	grandr-0.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	GTK2 utility for changing RandR settings

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
