# $NetBSD: Makefile,v 1.2 2007/03/28 18:07:11 bsadewitz Exp $
#

DISTNAME=		rgb-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/app/
COMMENT=		RGB database for X11 and showrgb tool

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
