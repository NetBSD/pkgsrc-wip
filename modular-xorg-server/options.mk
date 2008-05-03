# $NetBSD: options.mk,v 1.4 2008/05/03 16:46:20 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dbus dri inet6
# remove after 2007Q4
PKG_OPTIONS_LEGACY_OPTS=glx:dri
.if defined(PKG_OPTIONS.xorg-server)
PKG_LEGACY_OPTIONS+=	${PKG_OPTIONS.xorg-server}
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable PKG_OPTIONS.xorg-server used, use "${PKG_OPTIONS_VAR:Q}" instead."
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mdri)
.include "mesaconfig.mk"
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		MesaLib-7.0.3.tar.bz2
SITES.MesaLib-7.0.3.tar.bz2= ${MASTER_SITE_SOURCEFORGE:=mesa3d/}
PATCHFILES=		Mesa-7.0.3-001 Mesa-7.0.3-002
PATCH_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/patchfiles/
PATCH_DIST_ARGS+=	-d ${WRKDIR}/Mesa-7.0.3 -f -V nil -b .orig_dist -p1 || ${TRUE}
MESA_SRC=		${WRKDIR}/Mesa-7.0.3
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-aiglx
CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC}
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha"
GLX_DEFINES+=		-D__GLX_ALIGN64
.endif
CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
# glcore.h and dri_interface.h shipped with *proto are older than
# those in Mesa-7.0.2. Either patch them or trick the build into using
# the newer ones.
#BUILDLINK_API_DEPENDS.glproto+= glproto>=1.4.8nb1
#BUILDLINK_API_DEPENDS.xf86driproto+= xf86driproto>=2.0.3nb1
PLIST_SUBST+=		USE_DRI=""

dri-post-extract:
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL

.else
CONFIGURE_ARGS+=	--disable-glx
PLIST_SUBST+=		USE_DRI="@comment "

dri-post-extract:
	@${DO_NADA}

# for GLX we already have the Mesa source
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
