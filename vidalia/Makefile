# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:34 thomasklausner Exp $
#

DISTNAME=	vidalia-0.0.16
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://vidalia-project.net/dist/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://vidalia-project.net/dist/
COMMENT=	Graphical Tor controller based on Qt 4.x

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}

# should work with net/tor aswell
DEPENDS+=	tor-[0-9]*:../../net/tor

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
