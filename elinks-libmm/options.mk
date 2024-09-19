# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:34 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.elinks
PKG_SUPPORTED_OPTIONS+=		bittorrent nntp javascript finger gopher
PKG_SUPPORTED_OPTIONS+=		inet6 x11 elinks-exmode expat
PKG_SUPPORTED_OPTIONS+=		elinks-html-highlight elinks-root-exec libmm
PKG_OPTIONS_GROUP.tls=		gnutls ssl
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_SUGGESTED_OPTIONS=		inet6 ssl libmm

PKG_OPTIONS_LEGACY_OPTS=	spidermonkey:javascript

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mx11)

BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mbittorrent)
CONFIGURE_ARGS+=	--enable-bittorrent
.else
CONFIGURE_ARGS+=	--disable-bittorrent
.endif

.if !empty(PKG_OPTIONS:Mnntp)
CONFIGURE_ARGS+=	--enable-nntp
.else
CONFIGURE_ARGS+=	--disable-nntp
.endif

.if !empty(PKG_OPTIONS:Mjavascript)

.include "../../lang/ossp-js/buildlink3.mk"

CONFIGURE_ARGS+=	--with-spidermonkey=${BUILDLINK_PREFIX.ossp-js}
CONFIGURE_ARGS+=	--enable-sm-scripting
.else
CONFIGURE_ARGS+=	--without-spidermonkey
CONFIGURE_ARGS+=	--disable-sm-scripting
.endif

.if !empty(PKG_OPTIONS:Mssl)

.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.elif !empty(PKG_OPTIONS:Mgnutls)

.include "../../security/gnutls/buildlink3.mk"

CONFIGURE_ARGS+=	--with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+=	--with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
CONFIGURE_ARGS+=	--without-openssl
.endif

# Requires fsplib, which is not currently in pkgsrc.
#
#.if !empty(PKG_OPTIONS:Mfsp)
#CONFIGURE_ARGS+=	--enable-fsp
#.else
#CONFIGURE_ARGS+=	--disable-fsp
#.endif

.if !empty(PKG_OPTIONS:Mfinger)
CONFIGURE_ARGS+=	--enable-finger
.else
CONFIGURE_ARGS+=	--disable-finger
.endif

.if !empty(PKG_OPTIONS:Mgopher)
CONFIGURE_ARGS+=	--enable-gopher
.else
CONFIGURE_ARGS+=	--disable-gopher
.endif

.if !empty(PKG_OPTIONS:Mexpat)

.include "../../textproc/expat/buildlink3.mk"

CONFIGURE_ARGS+=	--enable-xbel
.else
CONFIGURE_ARGS+=	--disable-xbel
.endif

.if !empty(PKG_OPTIONS:Melinks-html-highlight)
CONFIGURE_ARGS+=	--enable-html-highlight
.else
CONFIGURE_ARGS+=	--disable-html-hightlight
.endif

.if !empty(PKG_OPTIONS:Melinks-exmode)
CONFIGURE_ARGS+=	--enable-exmode
.else
CONFIGURE_ARGS+=	--disable-exmode
.endif

.if !empty(PKG_OPTIONS:Melinks-root-exec)
CONFIGURE_ARGS+=	--disable-no-root
.else
CONFIGURE_ARGS+=	--enable-no-root
.endif

.if !empty(PKG_OPTIONS:Mlibmm)
LIBMM_DISABLED_DEFS=	CONFIG_DEBUG CONFIG_FASTMEM
LIBMM_DISABLED_DEFS+=	HAVE_MMAP HAVE_MREMAP HAVE_MUNMAP

CPPFLAGS+=		-DHAVE_LIBMM

LIBS+=			-lmm

SUBST_CLASSES+=		mm
SUBST_FILES.mm=		config.h.in
SUBST_MESSAGE.mm=	Modifying config.h for a libmm build.
SUBST_STAGE.mm=		pre-configure
SUBST_SED.mm=		# empty

.  for def in ${LIBMM_DISABLED_DEFS}
SUBST_SED.mm+=		-e 's,^.*\#.*${def}.*$$,,'
.  endfor
.  include "../../devel/libmm/buildlink3.mk"

pre-configure:
	${CP} ${FILESDIR}/memory.? ${WRKSRC}/src/util
.endif
