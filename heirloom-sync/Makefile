# $NetBSD: Makefile,v 1.3 2006/12/21 08:33:29 cheusov Exp $

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-sync-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build sync"

.include "../../mk/bsd.pkg.mk"
