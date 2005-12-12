# $NetBSD: version.mk,v 1.1 2005/12/12 17:42:17 lkundrak Exp $

.include "../../mk/bsd.prefs.mk"

GRUB_VERSION?=	${:!${DATE} '+%Y%m%d'!}
