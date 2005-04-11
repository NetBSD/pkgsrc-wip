# $NetBSD: Makefile,v 1.2 2005/04/11 21:16:18 tvierling Exp $
#

DISTNAME=	xmms-scrobbler-0.3.6
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://www.audioscrobbler.com/
COMMENT=	XMMS plugin for the Audioscrobbler music community

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
