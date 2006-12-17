# $NetBSD: Makefile,v 1.1 2006/12/17 22:47:16 cheusov Exp $

.include "../../wip/heirloom-dirs/Makefile.prog2.common"

PKGNAME=	heirloom-pg-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build pg"

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
