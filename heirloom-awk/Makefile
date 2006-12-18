# $NetBSD: Makefile,v 1.4 2006/12/18 20:11:22 cheusov Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-awk-${HEIRLOOM_VER}
CATEGORIES=	textproc lang

MAKE_FLAGS+=	SUBDIRS="libcommon build oawk nawk"

DOC_FILES=	NOTES

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
