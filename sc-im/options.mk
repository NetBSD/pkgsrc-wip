# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.sc-im
PKG_SUPPORTED_OPTIONS+=	xlsx lua

.include "../../mk/bsd.options.mk"

# reader only, writer needs libxlsxwriter
.if !empty(PKG_OPTIONS:Mxlsx)
CFLAGS+=	-DXLSX
.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlua)
CFLAGS+=	-DXLUA
.include "../../lang/lua51/buildlink3.mk"
.endif
