# $NetBSD: version.mk,v 1.1.1.1 2007/04/14 12:56:01 kibumh Exp $

.include "../../mk/bsd.prefs.mk"

GRUB_VERSION?=	${:!${DATE} '+%Y%m%d'!}
