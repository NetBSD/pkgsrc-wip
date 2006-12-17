# $NetBSD: Makefile,v 1.2 2006/12/17 15:42:12 cheusov Exp $

.include "../../wip/heirloom-dirs/Makefile.prog2.common"

PKGNAME=	heirloom-grep-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build grep"

DOC_FILES=	NOTES

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
