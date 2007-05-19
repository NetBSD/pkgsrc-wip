# $NetBSD: Makefile,v 1.4 2007/05/19 13:26:19 cheusov Exp $

NEED_LIBCURSES=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-ul-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build ul"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
