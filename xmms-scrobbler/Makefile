# $NetBSD: Makefile,v 1.8 2007/03/01 19:12:21 shattered Exp $
#

DISTNAME=	xmms-scrobbler_0.3.8.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xmms-scrobbler/}

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://www.last.fm/
COMMENT=	XMMS plugin for the Audioscrobbler music community

WRKSRC=		${WRKDIR}/${PKGNAME}/
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
