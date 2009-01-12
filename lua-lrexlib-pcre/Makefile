# $NetBSD: Makefile,v 1.4 2009/01/12 19:10:46 cheusov Exp $
#

ENGINE=		pcre

.include "../../wip/lua-lrexlib/Makefile.common"

COMMENT=	PCRE regexp library for Lua (lrexlib project)

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lpcre

.include "../../lang/lua/module.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
