# $NetBSD: Makefile,v 1.9 2007/04/24 15:24:09 tnn2 Exp $
#

DISTNAME=	xmms-scrobbler_0.3.8.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xmms-scrobbler/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.last.fm/
COMMENT=	XMMS plugin for the last.fm music community

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
