# $NetBSD: Makefile,v 1.5 2006/04/29 17:43:17 shattered Exp $
#

DISTNAME=	xmms-scrobbler-0.3.8
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/ \
		http://www.pipian.com/stuffforchat/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://www.last.fm/
COMMENT=	XMMS plugin for the Audioscrobbler music community

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
