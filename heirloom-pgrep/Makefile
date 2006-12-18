# $NetBSD: Makefile,v 1.3 2006/12/18 20:13:44 cheusov Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-pgrep-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build pgrep"

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
