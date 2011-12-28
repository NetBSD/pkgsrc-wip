# $NetBSD: Makefile,v 1.3 2011/12/28 00:13:14 mwilhelmy Exp $
#

DISTNAME=	libjingle-0.6.6
CATEGORIES=	chat
MASTER_SITES=	http://libjingle.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://code.google.com/p/libjingle/
COMMENT=	Google Talk Voice and P2P Interoperability Library

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

#PKGCONFIG_OVERRIDE+=	pkgconfig/jinglep2p.pc.in
#PKGCONFIG_OVERRIDE+=	pkgconfig/jinglebase.pc.in

.include "../../mk/bsd.pkg.mk"
