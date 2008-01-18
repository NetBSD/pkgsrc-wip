# $NetBSD: Makefile,v 1.11 2008/01/18 04:30:18 tnn2 Exp $
#

DISTNAME=	xmms-scrobbler_0.4.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xmms-scrobbler/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.last.fm/
COMMENT=	XMMS plugin for the last.fm music community

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS+=	--disable-bmp-plugin

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
