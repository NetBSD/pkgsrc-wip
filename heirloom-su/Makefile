# $NetBSD: Makefile,v 1.4 2007/05/19 13:26:18 cheusov Exp $

NEED_LIBCRYPT=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-su-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build su"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
