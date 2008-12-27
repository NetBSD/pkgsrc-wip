# $NetBSD: Makefile,v 1.1.1.1 2008/12/27 18:33:54 cheusov Exp $
#

.include "../../wip/lua-lrexlib/Makefile.common"

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)

ENGINE=		onig

DESCR_SRC+=	DESCR

LDFLAGS+=	-lonig

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
