# $NetBSD: Makefile,v 1.3 2006/12/18 19:13:20 cheusov Exp $

NEED_LIBUXRE=		1
NEED_LIBCRYPT=		1
NEED_ZLIB=		1
NEED_BZLIB=		1
NEED_LIBCURSES=		1

.include "../../wip/heirloom-common/Makefile.prog.common"

PKGNAME=	heirloom-toolchest-${HEIRLOOM_VER}

DEPENDS+=       heirloom-doc-${HEIRLOOM_VER}:../../wip/heirloom-doc

MAKE_FLAGS+=	NO_INSTALL_INTRO=1

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
