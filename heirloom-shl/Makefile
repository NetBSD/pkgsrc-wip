# $NetBSD: Makefile,v 1.5 2008/03/30 18:54:15 cheusov Exp $

NOT_FOR_PLATFORM+=	Interix-*-* NetBSD-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-shl-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build shl"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
