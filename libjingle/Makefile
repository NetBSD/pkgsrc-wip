# $NetBSD: Makefile,v 1.2 2009/09/13 15:09:47 yacht Exp $
#

DISTNAME=	libjingle-0.3.12
CATEGORIES=	chat
MASTER_SITES=	http://farsight.freedesktop.org/releases/libjingle/

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://farsight.freedesktop.org/releases/libjingle/
COMMENT=	Google Talk's implementation of Jingle and Jingle-Audio

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/jinglep2p.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/jinglebase.pc.in

.include "../../mk/bsd.pkg.mk"
