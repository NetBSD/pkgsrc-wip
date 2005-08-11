# $NetBSD: Makefile,v 1.9 2005/08/11 10:08:21 absd Exp $
#

DISTNAME=	dclib-0.3.7
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/dcgui/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect P2P library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	dclib.pc.in

.include "../../mk/bsd.prefs.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
