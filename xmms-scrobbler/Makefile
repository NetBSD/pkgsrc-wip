# $NetBSD: Makefile,v 1.4 2006/02/15 16:30:51 tnn2 Exp $
#

DISTNAME=	xmms-scrobbler-0.3.8
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/ \
		http://www.pipian.com/stuffforchat/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://www.audioscrobbler.com/
COMMENT=	XMMS plugin for the Audioscrobbler music community

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
