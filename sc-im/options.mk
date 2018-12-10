# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.sc-im
PKG_SUPPORTED_OPTIONS+=	xls xlsx lua
PKG_SUGGESTED_OPTIONS+=	xls xlsx lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxls)
CFLAGS+=	-DXLS
LDFLAGS+=	-lxlsreader
.include "../../wip/libxls/buildlink3.mk"
.endif

# reader only, writer needs libxlsxwriter
.if !empty(PKG_OPTIONS:Mxlsx)
CFLAGS+=	-DXLSX -DXLSX_WRITER
.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libxlsxwriter/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlua)
CFLAGS+=	-DXLUA
.include "../../lang/lua51/buildlink3.mk"
.endif
