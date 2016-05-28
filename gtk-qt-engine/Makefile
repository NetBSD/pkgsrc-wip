# $NetBSD: Makefile,v 1.9 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gtk-qt-engine-0.7
PKGREVISION=	7
CATEGORIES=	x11 devel
MASTER_SITES=	http://gtk-qt.ecs.soton.ac.uk/files/0.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://gtk-qt.ecs.soton.ac.uk/
COMMENT=	Theme engine for gtk2 which uses qt widgets


USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGBASE}


PKG_OPTIONS_VAR= PKG_OPTIONS.gtk-qt-engine
PKG_SUPPORTED_OPTIONS= arts

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
. include "../../audio/arts/buildlink3.mk"
 CONFIGURE_ARGS+= --with-arts
.else
 CONFIGURE_ARGS+= --without-arts
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
