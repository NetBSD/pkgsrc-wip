# $NetBSD: options.mk,v 1.24 2023/03/30 08:25:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dri
PKG_SUGGESTED_OPTIONS=	dri

.include "../../mk/bsd.options.mk"

# not supported on NetBSD
# FAILED: [code=1] dix/liblibxserver_dix.a.p/Xserver.o
# /usr/sbin/dtrace -G -s ../include/Xserver.d -o dix/liblibxserver_dix.a.p/Xserver.o
# dtrace: failed to compile script ../include/Xserver.d: "/usr/lib/dtrace/psinfo.d", line 46: syntax error near "u_int"
# and if that is fixed,
# dtrace: failed to compile script ../include/Xserver.d: line 26: invalid control directive: #ifdef
.if ${OPSYS} != "NetBSD"
PKG_SUPPORTED_OPTIONS+=	dtrace
.endif

PLIST_VARS+=		dri # dtrace

PRINT_PLIST_AWK+=	{ if (/include\/xorg\/dri/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/include\/xorg\/glamor/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/include\/xorg\/sarea/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/include\/xorg\/vndserver/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/libglamor/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/libglx/) $$0 = "$${PLIST.dri}" $$0 }
PRINT_PLIST_AWK+=	{ if (/modesetting/) $$0 = "$${PLIST.dri}" $$0 }

.if !empty(PKG_OPTIONS:Mdri)
.include "../../graphics/libepoxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
PLIST.dri=		yes
MESON_ARGS+=		-Ddri1=true
MESON_ARGS+=		-Ddri2=true
MESON_ARGS+=		-Ddri3=true
MESON_ARGS+=		-Dglx=true
.  if ${MESALIB_SUPPORTS_EGL:tl} == "yes"
MESON_ARGS+=		-Dglamor=true
.  endif
.else
###
### XXX Perhaps we should allow for a built-in glx without dri enabled?
###
MESON_ARGS+=		-Ddri1=false
MESON_ARGS+=		-Ddri2=false
MESON_ARGS+=		-Ddri3=false
MESON_ARGS+=		-Dglx=false
MESON_ARGS+=		-Dglamor=false
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
#PLIST.dtrace=		yes
MESON_ARGS+=		-Ddtrace=true
.else
MESON_ARGS+=		-Ddtrace=false
.endif
