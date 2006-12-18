# $NetBSD: Makefile,v 1.3 2006/12/18 19:54:13 cheusov Exp $

NEED_LIBUXRE=	1
NEED_LIBCURSES=	1

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-more-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="libcommon build more"

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
