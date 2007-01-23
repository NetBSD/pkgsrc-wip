# $NetBSD: Makefile,v 1.7 2007/01/23 13:35:09 bsadewitz Exp $
#

DISTNAME=	libXft-2.1.12
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://fontconfig.org
COMMENT=        Library for configuring and customizing font access
 
CONFLICTS+=     Xft2-[0-9]*
  
PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir
   
PKGCONFIG_OVERRIDE=     xft.pc.in
    
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xft.pc.in

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=      fontconfig>=2.2
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
     
.include "../../mk/bsd.pkg.mk"
