# $NetBSD: options.mk,v 1.1 2012/01/22 12:53:29 mwdavies Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kde-runtime4
PKG_SUPPORTED_OPTIONS=	samba alsa
PKG_DEFAULT_OPTIONS=	samba alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	smb
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
#CMAKE_ARGS+=	-DSAMBA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.samba}/include
#CMAKE_ARGS+=	-DSAMBA_LIBRARIES:FILEPATH=${BUILDLINK_PREFIX.samba}/lib/samba
PLIST.smb=	yes
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif
