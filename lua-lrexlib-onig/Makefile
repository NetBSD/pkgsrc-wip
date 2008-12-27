# $NetBSD: Makefile,v 1.1.1.1 2008/12/27 18:50:27 cheusov Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../wip/lua-lrexlib/Makefile.common"

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)

DESCR_SRC+=	DESCR

LDFLAGS+=	-lonig

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
