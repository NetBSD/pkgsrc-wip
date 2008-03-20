# $NetBSD: options.mk,v 1.7 2008/03/20 20:29:23 bsadewitz Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=	# Added to below

# Assembler code build configurations
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=		${MACHINE_ARCH}
.endif

###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we
### 	 support.
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "sparc64") && \
    (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD")
PKG_SUPPORTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"

###
### XXX Yes, this is a bit overly verbose; with Mesa, that can't hurt much.
###
.if !empty(PKG_OPTIONS:Mi386) || !empty(PKG_OPTIONS:Mx86_64)
BUILD_TARGET_SUFFIX=	-${MACHINE_ARCH}
.else
BUILD_TARGET_SUFFIX=	# empty
.endif

.if !empty(PKG_OPTIONS:Mdri)
BUILD_TARGET=	pkgsrc-dri${BUILD_TARGET_SUFFIX}
.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
PLIST_SUBST+=	DRI=""
PLIST_SUBST+=	NODRI="@comment"
.else
BUILD_TARGET=	pkgsrc${BUILD_TARGET_SUFFIX}
PLIST_SUBST+=	DRI="@comment "
PLIST_SUBST+=	NODRI=""
.endif
