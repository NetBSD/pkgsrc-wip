# $NetBSD: Makefile,v 1.6 2007/01/23 08:07:34 bsadewitz Exp $
#

DISTNAME=		libfontenc-1.0.4
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		blair.sadewitz@gmail.com
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The fontenc Library from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	fontenc.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
