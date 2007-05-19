# $NetBSD: Makefile,v 1.5 2007/05/19 13:26:12 cheusov Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-awk-${HEIRLOOM_VER}
CATEGORIES=	textproc lang

MAKE_FLAGS+=	SUBDIRS="build oawk nawk"

DOC_FILES=	NOTES

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
