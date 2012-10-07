# $NetBSD: Makefile,v 1.3 2012/10/07 16:22:56 asau Exp $
#

DISTNAME=		sflphoned-0.6.1
CATEGORIES=		chat
MASTER_SITES=		http://www.sflphone.org/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.sflphone.org/
COMMENT=		Multiplatform softphone for IP telephony using SIP (VOIP)

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-asound

# TODO make speex dependency optional?
.include "../../audio/speex/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
