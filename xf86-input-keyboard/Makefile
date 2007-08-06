# $NetBSD: Makefile,v 1.1 2007/08/06 21:59:56 bsadewitz Exp $

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

BUILDLINK_API_DEPENDS+=	modular-xorg-server>=1.3.99.0:../../wip/modular-xorg-server

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../wip/modular-xorg-server/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
