# $NetBSD: options.mk,v 1.8 2009/09/27 16:08:09 blef Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpg123
PKG_OPTIONS_REQUIRED_GROUPS=	cpu
PKG_OPTIONS_GROUP.cpu=		x86-dither generic-nofpu altivec generic-fpu
PKG_SUPPORTED_OPTIONS=		mpg123-no-fifo

.include "../../mk/bsd.fast.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
PKG_SUGGESTED_OPTIONS+=		x86-dither
.elif (${MACHINE_ARCH} == "arm") || (${MACHINE_ARCH} == "arm32")
PKG_SUGGESTED_OPTIONS+=		generic-nofpu
.elif (${MACHINE_ARCH} == "powerpc")
PKG_SUGGESTED_OPTIONS+=		altivec
.else
PKG_SUGGESTED_OPTIONS+=		generic-fpu
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeneric-nofpu)
CONFIGURE_ARGS+=	--with-cpu=generic_nofpu
.elif !empty(PKG_OPTIONS:Mgeneric-fpu)
CONFIGURE_ARGS+=	--with-cpu=generic_fpu
.elif !empty(PKG_OPTIONS:Maltivec)
CONFIGURE_ARGS+=	--with-cpu=altivec
.elif !empty(PKG_OPTIONS:Mx86-dither)
CONFIGURE_ARGS+=	--with-cpu=x86_dither
.elif !empty(PKG_OPTIONS:Maltivec)
CONFIGURE_ARGS+=	--with-cpu=altivec
.endif

.if !empty(PKG_OPTIONS:Mmpg123-no-fifo)
CONFIGURE_ARGS+=	--enable-fifo=no
.else
CONFIGURE_ARGS+=	--enable-fifo=yes
.endif
