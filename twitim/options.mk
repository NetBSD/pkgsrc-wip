# $NetBSD: options.mk,v 1.1 2010/11/13 13:59:33 ryo-on Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.twitim
PKG_SUPPORTED_OPTIONS=	gstreamer popup spell xmpp
PKG_SUGGESTED_OPTIONS=	spell

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
# not tested yet
DEPENDS+=	p5-GStreamer-[0-9]*:../../multimedia/p5-GStreamer
.endif

.if !empty(PKG_OPTIONS:Mpopup)
# not tested yet
DEPENDS+=	p5-Gnome2-[0-9]*:../../devel/p5-Gnome2
DEPENDS+=	p5-Net-DBus-GLib-[0-9]*:../../wip/p5-Net-DBus-GLib
.endif

.if !empty(PKG_OPTIONS:Mspell)
DEPENDS+=	p5-Gtk2-Spell-[0-9]*:../../wip/p5-Gtk2-Spell
.endif

.if !empty(PKG_OPTIONS:Mxmpp)
# not tested yet

.endif
