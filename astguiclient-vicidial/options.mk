# $NetBSD$
# Options for astGUIclient VICIdial

PKG_OPTIONS_VAR=	PKG_OPTIONS.vicidial
PKG_SUPPORTED_OPTIONS=	lame sox sipsak screen iftop openntpd ploticus ttyload
PKG_SUGGESTED_OPTIONS=	lame sox

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
.include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msox)
.include "../../audio/sox/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msipsak)
DEPENDS+=	sipsak>=0.9:../../net/sipsak
.endif

.if !empty(PKG_OPTIONS:Mscreen)
DEPENDS+=	screen>=4.0:../../misc/screen
.endif

.if !empty(PKG_OPTIONS:Miftop)
DEPENDS+=	iftop>=0.17:../../net/iftop
.endif

.if !empty(PKG_OPTIONS:Mopenntpd)
DEPENDS+=	openntpd>=6.0:../../net/openntpd
.endif

.if !empty(PKG_OPTIONS:Mploticus)
DEPENDS+=	ploticus>=2.42:../../graphics/ploticus
.endif

# Please note this is a WIP package, if you choose this
# option, there's no guarantee it will work efficiently.
.if !empty(PKG_OPTIONS:Mttyload)
DEPENDS+=	ttyloadp>=0.5:../../wip/ttyload
.endif
