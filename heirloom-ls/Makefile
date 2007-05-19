# $NetBSD: Makefile,v 1.4 2007/05/19 13:26:16 cheusov Exp $

NEED_LIBCURSES=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-ls-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build ls"

.include "../../wip/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
