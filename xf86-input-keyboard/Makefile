# $NetBSD: Makefile,v 1.2 2007/12/13 15:51:54 rillig Exp $

DISTNAME=	xf86-input-keyboard-1.2.1
CATEGORIES=	x11
MASTER_SITES=	http://bahar.aydogan.net/~blair/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
COMMENT=	Modular Xorg keyboard driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

BUILD_DEPENDS+=		modular-xorg-server>=1.4:../../wip/modular-xorg-server14

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
