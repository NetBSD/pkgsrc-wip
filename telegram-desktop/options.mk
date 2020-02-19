# $NetBSD$

PKG_OPTIONS_VAR=          PKG_OPTIONS.telegram-desktop

PKG_SUPPORTED_OPTIONS=    gtk3 spell dbus libressl

.include "../../mk/bsd.options.mk"

###
### GTK+3 integration
###
.if !empty(PKG_OPTIONS:Mgtk3)
CMAKE_ARGS+=              -DTDESKTOP_DISABLE_GTK_INTEGRATION=OFF
CMAKE_ARGS+=              -DTDESKTOP_FORCE_GTK_FILE_DIALOG=ON
.include "../../devel/libappindicator/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.else
CMAKE_ARGS+=              -DTDESKTOP_DISABLE_GTK_INTEGRATION=ON
CMAKE_ARGS+=              -DTDESKTOP_FORCE_GTK_FILE_DIALOG=OFF
.endif

###
### Spell checking
###
.if !empty(PKG_OPTIONS:Mspell)
CMAKE_ARGS+=              -DDESKTOP_APP_DISABLE_SPELLCHECK=OFF
.include "../../textproc/enchant/buildlink3.mk"
.else
CMAKE_ARGS+=              -DDESKTOP_APP_DISABLE_SPELLCHECK=ON
.endif

###
### D-Bus integration
###
.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_ARGS+=              -DTDESKTOP_DISABLE_DBUS_INTEGRATION=OFF
.include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_ARGS+=              -DTDESKTOP_DISABLE_DBUS_INTEGRATION=ON
.endif

###
### LibreSSL
###
.if !empty(PKG_OPTIONS:Mlibressl)
.include "../../security/libressl/buildlink3.mk"
.else
.include "../../security/openssl/buildlink3.mk"
.endif

###
### PulseAudio
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../security/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=           -DTDESKTOP_WITHOUT_PULSE=OFF
.else
CMAKE_ARGS+=           -DTDESKTOP_WITHOUT_PULSE=ON
.endif

