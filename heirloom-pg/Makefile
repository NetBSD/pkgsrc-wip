# $NetBSD: Makefile,v 1.3 2006/12/18 20:14:22 cheusov Exp $

NEED_LIBUXRE=	1
NEED_LIBCURSES=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-pg-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build pg"

.include "../../mk/curses.buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
