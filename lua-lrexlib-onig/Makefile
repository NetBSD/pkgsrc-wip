# $NetBSD: Makefile,v 1.3 2009/01/12 19:10:46 cheusov Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../wip/lua-lrexlib/Makefile.common"

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
