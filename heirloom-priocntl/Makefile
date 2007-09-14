# $NetBSD: Makefile,v 1.4 2007/09/14 06:38:47 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-priocntl-${HEIRLOOM_VER}
CATEGORIES=	textproc

NOT_FOR_PLATFORM+=	Linux-*-*
NOT_FOR_PLATFORM+=	Interix-*-*

MAKE_FLAGS+=		SUBDIRS="build priocntl"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
