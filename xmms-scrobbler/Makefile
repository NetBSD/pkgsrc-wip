# $NetBSD: Makefile,v 1.1.1.1 2005/03/03 18:45:34 tnn2 Exp $
#

DISTNAME=	xmms-scrobbler-0.3.6
CATEGORIES=	audio
MASTER_SITES=	http://static.audioscrobbler.com/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://www.audioscrobbler.com/
COMMENT=	XMMS plugin for the Audioscrobbler music community

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
