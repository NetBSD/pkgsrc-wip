# $NetBSD: Makefile,v 1.4 2007/05/19 13:26:19 cheusov Exp $

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-uname-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build uname"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
