# $NetBSD: version.mk,v 1.1.1.1 2007/02/20 15:54:44 lkundrak Exp $

.include "../../mk/bsd.prefs.mk"

FLV2MPEG_VERSION?=	${:!${DATE} '+%Y%m%d'!}
