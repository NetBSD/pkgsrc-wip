# $NetBSD: Makefile,v 1.3 2006/06/08 11:14:27 absd Exp $
#

DISTNAME=		obby-0.3.0
PKGNAME=		libobby-0.3.0
CATEGORIES=		devel net
MASTER_SITES=		http://releases.0x539.de/obby/

MAINTAINER=	 	evaldo@gardenali.biz
HOMEPAGE=		http://releases.0x539.de/obby/
COMMENT=		Synced document buffers library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/obby-0.3.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++

.include "options.mk"

pre-install:
	${INSTALL_LIB_DIR} ${PREFIX}/include/obby/serialise

PLIST_SRC+=             ${PKGDIR}/PLIST.common

.include "../../wip/net6/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
