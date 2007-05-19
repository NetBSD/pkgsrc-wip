# $NetBSD: Makefile,v 1.6 2007/05/19 13:26:15 cheusov Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-grep-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build grep"

DOC_FILES=	NOTES

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
