# $NetBSD: Makefile,v 1.79 2016/08/03 10:23:24 adam Exp $
#

DISTNAME=	gvfs-1.30.4
PKGREVISION=	24
CATEGORIES?=	sysutils 
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.30/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Userspace virtual filesystem
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake gettext-m4 \
		gmake gm4 intltool msgfmt pkg-config
CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--disable-keyring
CONFIGURE_ARGS+=	--disable-admin
CONFIGURE_ARGS+=	--disable-silent-rules
CONFIGURE_ARGS+=	--enable-bash-completion

PLIST_SRC=	/dev/null
GENERATE_PLIST=	cd ${DESTDIR}${LOCALBASE};find * \! -type d;

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=        PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+= fuse samba hal
PKG_SUGGESTED_OPTIONS+= samba 
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# XXX fuse.bl3.mk will fail if we include it and fuse is not available
.if ${OPSYS} == "Linux" #|| (${OPSYS} == "NetBSD" && exists(/usr/include/fuse.h))
PKG_SUGGESTED_OPTIONS+=	fuse
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msamba)
CONFIGURE_ARGS+=	--with-samba-includes=${BUILDLINK_PREFIX.samba}/include
CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib
.include "../../net/samba/buildlink3.mk"
PLIST.samba=		yes
.else
CONFIGURE_ARGS+=	--disable-samba
.endif

.if !empty(PKG_OPTIONS:Mnohal)
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../wip/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
CONFIGURE_ARGS+=	--enable-cdda
PLIST.hal=		yes
.else
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-cdda
.endif

.if !empty(PKG_OPTIONS:Mfuse)
#.include "../../mk/fuse.buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fuse
PLIST.fuse=		yes
.else
CONFIGURE_ARGS+=	--disable-fuse
.endif

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED

DBUS_CFLAGS!=		pkg-config --cflags dbus-1
CFLAGS+=		${DBUS_CFLAGS}
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500 -D__EXTENSIONS__


#BUILDLINK_DEPMETHOD.autogen+= build
#.include "../../devel/autogen/buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf --force --install


DEPENDS+=	glib-networking:../../net/glib-networking

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.23.4
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.26.0
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../security/polkit/buildlink3.mk"
.include "../../wip/gnome-mount/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
