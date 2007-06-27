PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_OPTIONS_SET.driver=	dri-i810 dri-i915 dri-i965 dri-mach64 dri-mga
PKG_OPTIONS_SET.driver+=dri-r128 dri-r200 dri-r300 dri-radeon dri-tdfx dri-unichrome 
PKG_OPTIONS_SET.driver+=dri-savage dri-sis
PKG_OPTIONS_NONEMPTY_SETS=	driver

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_OPTIONS_GROUP.asm=	x86
PKG_OPTIONS_OPTIONAL_GROUPS=	asm
.elif ${MACHINE_ARCH} == "x86_64"
PKG_OPTIONS_GROUP.asm=	x86_64
PKG_OPTIONS_OPTIONAL_GROUPS=	asm
.endif

.include "../../mk/bsd.options.mk"

.for _drv in ${PKG_OPTIONS:Mdri-*}
PLIST_SUBST+=	${_drv}=""
DRI_DRIVERS+=	${_drv:S/dri-//}
.endfor

.for _drv in ${PKG_OPTIONS_SET.driver}
.  if empty(PKG_OPTIONS:M${_drv})
PLIST_SUBST+=	${_drv}="@comment "
.  endif
.endfor

.if !empty(PKG_OPTIONS:Mx86)
BUILD_TARGET=	netbsd-dri-x86
.elif !empty(PKG_OPTIONS:Mx86_64)
BUILD_TARGET=	netbsd-dri-amd64
CFLAGS+=	-D__GLX_ALIGN64
.else
BUILD_TARGET=	netbsd-dri
.endif

