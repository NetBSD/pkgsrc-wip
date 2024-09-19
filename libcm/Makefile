# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:37 asau Exp $

DISTNAME=	libcm-0.1.1
CATEGORIES=	wm devel gnome
#MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/libcm/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Metacity compositor library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	cm.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
