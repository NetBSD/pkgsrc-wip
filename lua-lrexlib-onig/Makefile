# $NetBSD: Makefile,v 1.4 2011/05/29 08:38:07 cheusov Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../wip/lua-lrexlib/Makefile.common"

PKGREVISION=	1
COMMENT=	Oniguruma regexp library for Lua (lrexlib project)

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
