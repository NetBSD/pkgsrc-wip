# $NetBSD: Makefile,v 1.4 2007/05/19 13:26:17 cheusov Exp $

NEED_LIBUXRE=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-nl-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build nl"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
