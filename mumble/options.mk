# $NetBSD: options.mk,v 1.1.1.1 2010/11/05 16:01:32 ggergely Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mumble
PKG_SUPPORTED_OPTIONS=	 dbus alsa portaudio pulseaudio oss bonjour
PKG_SUGGESTED_OPTIONS=	dbus portaudio bonjour 

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# TODO: XXX: no daemon yet. Maybe next time. Until then: wip/umurmurd
# XXX: and when doing daemon, do it in annother package!
# XXX: then both will be compiled by bulk, and one can choose what to install!
CONFIG_OPTIONS+=	CONFIG+=no-server
# disable compatibility with old servers
CONFIG_OPTIONS+=	CONFIG+=no-11x
# use pkgsrc celt
CONFIG_OPTIONS+=	CONFIG+=no-bundled-celt
# use pkgsrc speex
CONFIG_OPTIONS+=	CONFIG+=no-bundled-speex
# no support for fancy keyboard. i couldn't test it. feel free to add it
CONFIG_OPTIONS+=	CONFIG+=no-g15
# don't check for updates - pkgsrc should deliver them! :)
CONFIG_OPTIONS+=	CONFIG+=no-update
# XXX:  needed only in the server to make it able to talk to cgi and similiar stuff
CONFIG_OPTIONS+=	CONFIG+=no-ice
# we lack system-wide Qt translations, so couldn't be included anyway
CONFIG_OPTIONS+=	CONFIG+=no-embed-qt-translations
# XXX: i couldn't test it. if you need/can enable it, and test it!
CONFIG_OPTIONS+=	CONFIG+=no-overlay
# no speech dispatcher - cannot use multiple sound device
# simultanously on NetBSD yet anyway
# TODO: XXX: add speechd option!
CONFIG_OPTIONS+=	CONFIG+=no-speechd


# maybe enable it? The deaemon does need it anyway
.if !empty(PKG_OPTIONS:Mdbus)
#CONFIG_OPTIONS+=	CONFIG+=dbus
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-dbus
.endif

# make this crap and option - though pulseaudio should die
.if !empty(PKG_OPTIONS:Mpulseaudio)
#CONFIG_OPTIONS+=	CONFIG+=pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-pulseaudio
.endif

# TODO: XXX: check if it is oss4?
.if !empty(PKG_OPTIONS:Moss)
#what now?
CONFIG_OPTIONS+=	CONFIG+=oss
.else
CONFIG_OPTIONS+=	CONFIG+=no-oss
.endif

# XXX: we use no alsa, at most on linux
# TODO: XXX: someone please test it!
.if !empty(PKG_OPTIONS:Malsa)
#CONFIG_OPTIONS+=	CONFIG+=alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-alsa
.endif

# add an option for it
#avahi | or bonjour
.if !empty(PKG_OPTIONS:Mbonjour)
#CONFIG_OPTIONS+=	CONFIG+=bonjour
.include "../../net/mDNSResponder/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-bonjour
.endif
