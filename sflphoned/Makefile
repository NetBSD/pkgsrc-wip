# $NetBSD: Makefile,v 1.5 2013/04/21 17:47:48 kristerw Exp $
#

DISTNAME=		sflphoned-0.6.1
CATEGORIES=		chat
MASTER_SITES=		http://www.sflphone.org/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sflphone.org/
COMMENT=		Multiplatform softphone for IP telephony using SIP (VOIP)


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-asound

# TODO make speex dependency optional?
.include "../../audio/speex/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
