# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS=	dnssd libgdata samba gcr secret
PKG_SUGGESTED_OPTIONS=	dnssd secret

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Linux"
# polkit itself is cross-platform but gvfs also requires libcap, which is
# only available on Linux.
PKG_SUPPORTED_OPTIONS+=	polkit
PKG_SUGGESTED_OPTIONS+=	polkit
.endif

GUDEV_REQUIRED=	no
GOA_REQUIRED=	no

###
### admin:///
###   Access local filesystem as a root user.
###
PLIST_VARS+=	admin
.if !empty(PKG_OPTIONS:Mpolkit)
MESON_ARGS+=	-Dadmin=true
PLIST.admin=	yes
.  include "../../sysutils/libcap/buildlink3.mk"
.  include "../../security/polkit/buildlink3.mk"
.else
MESON_ARGS+=	-Dadmin=false
.endif

###
### dns-sd://{DOMAIN}
###   DNS-SD shares on the local network.
###
PLIST_VARS+=	dnssd
.if !empty(PKG_OPTIONS:Mdnssd)
MESON_ARGS+=	-Ddnssd=true
PLIST.dnssd=	yes
.  include "../../net/avahi/buildlink3.mk"
.else
MESON_ARGS+=	-Ddnssd=false
.endif

###
### google-drive://{USER}@{HOST}
###   Access Google Drive.
###
PLIST_VARS+=	google
.if !empty(PKG_OPTIONS:Mlibgdata)
MESON_ARGS+=	-Dgoogle=true
PLIST.google=	yes
GOA_REQUIRED=	yes
.  include "../../net/libgdata/buildlink3.mk"
.else
MESON_ARGS+=	-Dgoogle=false
.endif

###
### smb://[user@]host[:port][/share]
###   SMB/CIFS protocol support.
###
PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
MESON_ARGS+=	-Dsmb=true
PLIST.smb=	yes
.  include "../../net/samba4/buildlink3.mk"
.else
MESON_ARGS+=	-Dsmb=false
.endif

###
### GCR support.
###
.if !empty(PKG_OPTIONS:Mgcr)
MESON_ARGS+=	-Dgcr=true
.  include "../../wip/gcr4/buildlink3.mk"
.else
MESON_ARGS+=	-Dgcr=false
.endif

###
### GNOME Keyring support.
###
.if !empty(PKG_OPTIONS:Msecret)
MESON_ARGS+=	-Dkeyring=true
.  include "../../security/libsecret/buildlink3.mk"
.else
MESON_ARGS+=	-Dkeyring=false
.endif
