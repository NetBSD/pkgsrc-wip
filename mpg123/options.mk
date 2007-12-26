PKG_OPTIONS_VAR=		PKG_OPTIONS.mpg123

.include "../../mk/bsd.fast.prefs.mk"

MPG123_OPTIONS.fpu=	generic_fixed generic_fpu generic_nofpu

PKG_OPTIONS_GROUP.i386=		x86_dither
PKG_OPTIONS_GROUP.powerpc=	altivec

PKG_OPTIONS_OPTIONAL_GROUPS=	${MACHINE_ARCH} 

PKG_SUPPORTED_OPTIONS+=		mpg123-no-fifo
PKG_SUGGESTED_OPTIONS.${MACHINE_ARCH}?=	generic_fpu
PKG_SUGGESTED_OPTIONS.arm=		generic_fixed
PKG_SUGGESTED_OPTIONS.arm32=		generic_fixed
PKG_SUGGESTED_OPTIONS.i386=		x86_dither
PKG_SUGGESTED_OPTIONS.powerpc=		altivec

.if defined(PKG_OPTIONS_GROUP.${MACHINE_ARCH})
PKG_OPTIONS_GROUP.fpu=		${MPG123_OPTIONS.fpu}
PKG_OPTIONS_OPTIONAL_GROUPS+=	fpu
.else
PKG_OPTIONS_SET.fpu=		${MPG123_OPTIONS.fpu}
PKG_OPTIONS_NONEMPTY_SETS+=	${MPG123_OPTIONS.fpu}
.endif

PKG_SUGGESTED_OPTIONS=	${PKG_SUGGESTED_OPTIONS.${MACHINE_ARCH}}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeneric_*)
CONFIGURE_ARGS+=	--with-cpu=${PKG_OPTIONS:Mgeneric_*)
.elif defined(PKG_OPTIONS_GROUP.${MACHINE_ARCH})
CONFIGURE_ARGS+=	--with-cpu=${PKG_OPTIONS_GROUP.${MACHINE_ARCH}:@.o.@${PKG_OPTIONS:M${.o.}}@}
.endif

.if !empty(PKG_OPTIONS:Mmpg123-no-fifo)
CONFIGURE_ARGS+=	--enable-fifo=no
.else
CONFIGURE_ARGS+=	--enable-fifo=yes
.endif
