# $NetBSD: Makefile,v 1.5 2005/02/22 08:20:39 tnn2 Exp $
#

DISTNAME=	dclib-0.3.7
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/dcgui/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect P2P library

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make

PKGCONFIG_OVERRIDE+=	dclib.pc.in

.include "../../mk/bsd.prefs.mk"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
