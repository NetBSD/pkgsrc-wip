# $NetBSD: Makefile,v 1.9 2007/08/22 18:19:56 bsadewitz Exp $
#

DISTNAME=	pixman-0.9.4
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2


MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org pixman library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	pixman-1.pc.in


.include "../../mk/bsd.pkg.mk"
