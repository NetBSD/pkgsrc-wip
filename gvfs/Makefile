# $NetBSD: Makefile,v 1.79 2016/08/03 10:23:24 adam Exp $
#

DISTNAME=	gvfs-1.58.0
CATEGORIES?=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/${PKGVERSION_NOREV:S/./ /g:[1..2]:ts.}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://wiki.gnome.org/Projects/gvfs
COMMENT=	Userspace virtual filesystem
LICENSE=	gnu-lgpl-v2

# TODO: Remove this line. Dunno why but mk/tools/replace.mk dies without it.
USE_TOOLS+=	gm4

USE_TOOLS+=	pkg-config

.include "options.mk"
.include "../../mk/bsd.fast.prefs.mk"

# SystemD support is obviously only for Linux.
.if ${OPSYS} != "Linux"
MESON_ARGS+=	-Dsystemduserunitdir=no
MESON_ARGS+=	-Dtmpfilesdir=no
.endif

# afc://{UUID}
#   Apple File Conduit; allow to exchange files with iOS devices
MESON_ARGS+=	-Dafc=true
.include "../../wip/libimobiledevice/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"

# afp://[user@]host[:port][/share]
#   Apple Filing Protocol.
MESON_ARGS+=	-Dafp=true

# archive://{URL-ENCODED-URI}
#   Access archive files.
MESON_ARGS+=	-Darchive=true
.include "../../archivers/libarchive/buildlink3.mk"

# burn://{DEVICE}
#   Virtual filesystem for file managers to help them implement burning
#   optical discs.
MESON_ARGS+=	-Dburn=true

# cdda://{DEVICE}
#   Access audio discs.
PLIST_VARS+=	cdda
.if ${OPSYS} == "Linux"
MESON_ARGS+=	-Dcdda=true
PLIST.cdda=	yes
# libcdio-paranoia is a cross-platform library but the gvfs backend relies
# on udev, which is only available on Linux.
GUDEV_REQUIRED=	yes
.  include "../../misc/libcdio-paranoia/buildlink3.mk"
.else
MESON_ARGS+=	-Dcdda=false
.endif

# gphoto2://{ID_SERIAL}, gphoto2://[usb:bus,dev]
#   Access digital cameras.
PLIST_VARS+=	gphoto2
.if ${OPSYS} == "Linux"
MESON_ARGS+=	-Dgphoto2=true
PLIST.gphoto2=	yes
GUDEV_REQUIRED=	yes
.  include "../../devel/libgphoto2/buildlink3.mk"
.else
MESON_ARGS+=	-Dgphoto2=false
.endif

# mtp://{ID_SERIAL}, mtp://[usb:bus,dev]
#   Access digital audio/media players.
PLIST_VARS+=	mtp
.if ${OPSYS} == "Linux"
MESON_ARGS+=	-Dmtp=true
PLIST.mtp=	yes
GUDEV_REQUIRED=	yes
.  include "../../devel/libmtp/buildlink3.mk"
.else
MESON_ARGS+=	-Dmtp=false
.endif

# http://, https://
#   HTTP protocol support.
MESON_ARGS+=	-Dhttp=true
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"

# nfs://{HOST}/{SHARE}
#   NFS v2 and v3 protocols.
MESON_ARGS+=	-Dnfs=true
.include "../../wip/libnfs/buildlink3.mk"

# OneDrive support requires libmsgraph-1 but we haven't packaged it
# yet. Nobody would want to use it anyway.
MESON_ARGS+=	-Donedrive=false

# sftp://[user@]host[:port], ssh://[user@]host[:port]
#   SFTP protocol support.
MESON_ARGS+=	-Dsftp=true

# ufisks2 support requires libudisks2 but we haven't packaged it yet. It's
# only for Linux anyway.
MESON_ARGS+=	-Dudisks2=false

# wsdd:///
#   Access Web Service Discovery Daemon.
MESON_ARGS+=	-Dwsdd=true

# Blu-Ray metadata support.
MESON_ARGS+=	-Dbluray=true
.include "../../multimedia/libbluray/buildlink3.mk"

# FUSE support.
MESON_ARGS+=	-Dfuse=true
.include "../../mk/fuse.buildlink3.mk"

# libgcrypt support.
MESON_ARGS+=	-Dgcrypt=true
.include "../../security/libgcrypt/buildlink3.mk"

# logind support requires libelogind but we haven't packaged it yet. It's
# only for Linux anyway.
MESON_ARGS+=	-Dlogind=false

# libusb-1 support: Not available on DragonFly.
.if ${OPSYS} == "DragonFly"
MESON_ARGS+=	-Dlibusb=false
.else
MESON_ARGS+=	-Dlibusb=true
.  include "../../devel/libusb1/buildlink3.mk"
.endif

# Generate man pages.
MESON_ARGS+=	-Dman=true

# Some options require libgudev, which is only available on Linux.
.if ${GUDEV_REQUIRED:tl} == "yes"
MESON_ARGS+=	-Dgudev=true
.  include "../../devel/libgudev/buildlink3.mk"
.else
MESON_ARGS+=	-Dgudev=false
.endif

# Some options require gnome-online-accounts, which is supposedly
# universally available but users would have a reason not to want it by
# default.
.if ${GOA_REQUIRED:tl} == "yes"
MESON_ARGS+=	-Dgoa=true
.  include "../../net/gnome-online-accounts/buildlink3.mk"
.else
MESON_ARGS+=	-Dgoa=false
.endif

.include "../../devel/glib2/modules.mk"
.include "../../devel/meson/build.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
