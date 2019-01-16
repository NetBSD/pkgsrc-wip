# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.sc-im
PKG_SUPPORTED_OPTIONS+=	xlsx lua
PKG_SUGGESTED_OPTIONS+=	xlsx lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxlsx)
CFLAGS+=	-DXLSX -DXLSX_EXPORT
LDFLAGS+=	-lxlsxwriter
.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libxlsxwriter/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua51/buildlink3.mk"
.endif
