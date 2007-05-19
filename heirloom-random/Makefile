# $NetBSD: Makefile,v 1.3 2007/05/19 13:26:18 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-random-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build random"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
