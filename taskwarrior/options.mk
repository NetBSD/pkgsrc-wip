# $NetBSD: Makefile,v 1.16 2015/08/10 21:16:48 yhardy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.taskwarrior
PKG_SUPPORTED_OPTIONS=	lua
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.endif
