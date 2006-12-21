# $NetBSD: Makefile,v 1.3 2006/12/21 08:33:30 cheusov Exp $

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-dd-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build dd"

.include "../../mk/bsd.pkg.mk"
