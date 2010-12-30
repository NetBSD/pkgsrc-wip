# $NetBSD: options.mk,v 1.1 2010/12/30 18:44:14 mjoellnir Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-xcache

PKG_SUPPORTED_OPTIONS=	constant optimizer coverager assembler disassembler encoder decoder
PKG_SUGGESTED_OPTIONS=	constant optimizer coverager

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mconstant)
CONFIGURE_ARGS+=	--enable-xcache-constant
.endif

.if !empty(PKG_OPTIONS:Moptimizer)
CONFIGURE_ARGS+=	--enable-xcache-optimizer
.endif

.if !empty(PKG_OPTIONS:Mcoverager)
CONFIGURE_ARGS+=	--enable-xcache-coverager
.endif

.if !empty(PKG_OPTIONS:Massembler)
CONFIGURE_ARGS+=	--enable-xcache-assembler
.endif

.if !empty(PKG_OPTIONS:Mdisassembler)
CONFIGURE_ARGS+=	--enable-xcache-disassembler
.endif

.if !empty(PKG_OPTIONS:Mencoder)
CONFIGURE_ARGS+=	--enable-xcache-encoder
.endif

.if !empty(PKG_OPTIONS:Mdecoder)
CONFIGURE_ARGS+=	--enable-xcache-decoder
.endif
