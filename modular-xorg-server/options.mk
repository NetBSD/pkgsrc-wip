# $NetBSD: options.mk,v 1.8 2008/08/19 09:10:55 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dri inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri

.if !empty(PKG_OPTIONS:Mdri)
PLIST.dri=		yes
.include "mesaconfig.mk"
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		MesaLib-7.0.4.tar.bz2
SITES.MesaLib-7.0.4.tar.bz2=\
			${MASTER_SITE_SOURCEFORGE:=mesa3d/}
MESA_SRC=		${WRKDIR}/Mesa-7.0.4
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
###
### XXX As of driproto-2.0.4 and glproto-1.4.9, this should not be needed.
###
dri-post-extract:
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL

.else
###
### XXX Do we want this?
###
CONFIGURE_ARGS+=	--disable-glx

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
