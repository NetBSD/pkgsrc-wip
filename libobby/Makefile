# $NetBSD: Makefile,v 1.1.1.1 2005/09/11 05:26:43 udontknow Exp $
#

DISTNAME=		obby-0.2.0
PKGNAME=		libobby-0.2.0
CATEGORIES=		devel net
MASTER_SITES=		http://releases.0x539.de/obby/

MAINTAINER=	 	evaldo@gardenali.biz
HOMEPAGE=		http://0x539.de/
COMMENT=		Synced document buffers library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/obby-0.2.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

PLIST_SRC+=             ${PKGDIR}/PLIST.common

.include "../../wip/net6/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
