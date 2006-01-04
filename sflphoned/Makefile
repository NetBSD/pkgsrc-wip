# $NetBSD: Makefile,v 1.1.1.1 2006/01/04 16:27:55 poppnk Exp $
#

DISTNAME=		sflphoned-0.6.1
CATEGORIES=		chat
MASTER_SITES=		http://www.sflphone.org/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.sflphone.org/
COMMENT=		Your desktop VoIP software.

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--disable-asound

# TODO make speex dependency optional?
.include "../../audio/speex/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
