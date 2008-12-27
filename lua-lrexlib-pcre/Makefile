# $NetBSD: Makefile,v 1.2 2008/12/27 18:49:57 cheusov Exp $
#

ENGINE=		pcre

.include "../../wip/lua-lrexlib/Makefile.common"

COMMENT=	PCRE regexp library for Lua (lrexlib project)

DESCR_SRC+=	DESCR

LDFLAGS+=	-lpcre

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
