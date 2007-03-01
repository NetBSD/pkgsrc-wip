# $NetBSD: Makefile,v 1.5 2007/03/01 19:12:17 shattered Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-grep-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build grep"

DOC_FILES=	NOTES

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
