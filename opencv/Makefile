# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:48 shattered Exp $
#

DISTNAME=		opencv-0.9.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}

MAINTAINER=		anthony.mallet@laas.fr
HOMEPAGE=		http://opencvlibrary.sourceforge.net/
COMMENT=		Library for computer vision problems

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake autoconf automake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
AUTOMAKE_REQD=	1.9

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	opencv.pc.in

CONFIGURE_ARGS+=--with-swig=no
CONFIGURE_ARGS+=--with-python=no

pre-configure:
	cd ${WRKSRC};				\
	automake -a --foreign -i; autoconf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
