# $NetBSD: Makefile,v 1.4 2008/03/30 18:56:42 cheusov Exp $

NOT_FOR_PLATFORM+=	NetBSD-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-time-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build time"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
