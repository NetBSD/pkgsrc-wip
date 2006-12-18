# $NetBSD: Makefile,v 1.2 2006/12/18 18:59:57 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-pg-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build pg"

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
