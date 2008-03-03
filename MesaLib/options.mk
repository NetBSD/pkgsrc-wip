# $NetBSD: options.mk,v 1.3 2008/03/03 02:20:23 tnn2 Exp $

.  include "../../mk/bsd.fast.prefs.mk"

###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we 
### 	 support.
### 	 
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "sparc64") && \
    (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD")
    
PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS= 	dri
PKG_SUGGESTED_OPTIONS=	dri # doesn't build without this option

.include "../../mk/bsd.options.mk"

###
### XXX Yes, this is a bid overly verbose; with Mesa, that can't
### 	hurt much.
###
.if !empty(PKG_OPTIONS:Mdri)
BUILD_TARGET= 	pkgsrc-dri
.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
.endif

.endif
