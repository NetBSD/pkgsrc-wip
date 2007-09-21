# $NetBSD: Makefile,v 1.6 2007/09/21 13:06:54 thomasklausner Exp $
#

DISTNAME=		obby-0.3.0
PKGNAME=		libobby-0.3.0
PKGREVISION=		1
CATEGORIES=		devel net
MASTER_SITES=		http://releases.0x539.de/obby/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://releases.0x539.de/obby/
COMMENT=		Synced document buffers library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/obby-0.3.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

.include "options.mk"

pre-install:
	${INSTALL_LIB_DIR} ${PREFIX}/include/obby/serialise

PLIST_SRC+=		${PKGDIR}/PLIST.common

.include "../../wip/net6/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
