# $NetBSD: Makefile,v 1.5 2007/12/27 21:26:23 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-priocntl-${HEIRLOOM_VER}
CATEGORIES=	textproc

ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*

MAKE_FLAGS+=		SUBDIRS="build priocntl"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
