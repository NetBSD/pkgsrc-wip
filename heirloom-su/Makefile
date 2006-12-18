# $NetBSD: Makefile,v 1.3 2006/12/18 20:34:37 cheusov Exp $

NEED_LIBCRYPT=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-su-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build su"

.include "../../mk/bsd.pkg.mk"
