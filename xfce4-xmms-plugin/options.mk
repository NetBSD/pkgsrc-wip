PKG_OPTIONS_VAR=		PKG_OPTIONS.xfce4-xmms-plugin
PKG_SUPPORTED_OPTIONS=
PKG_OPTIONS_REQUIRED_GROUPS+=	xfce4-xmms-plugin-player
PKG_OPTIONS_GROUP.xfce4-xmms-plugin-player=	xmms bmp audacious
PKG_SUGGESTED_OPTIONS=		xmms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maudacious)
.include "../../wip/audacious/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mbmp)
.include "../../audio/bmp/buildlink3.mk"
.else
.include "../../audio/xmms/buildlink3.mk"
.endif
