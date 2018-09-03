# $NetBSD$

BUILD_DIRS=	main/lib/inotify
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-inotify-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Filesystem event monitoring for Gambas

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
.include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
