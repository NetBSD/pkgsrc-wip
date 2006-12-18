# $NetBSD: Makefile,v 1.2 2006/12/18 18:59:59 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.prog.common"

PKGNAME=	heirloom-toolchest-${HEIRLOOM_VER}

DEPENDS+=       heirloom-doc-${HEIRLOOM_VER}:../../wip/heirloom-doc

MAKE_FLAGS+=	NO_INSTALL_INTRO=1

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
