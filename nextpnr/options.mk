# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.nextpnr

PKG_OPTIONS_REQUIRED_GROUPS=	arch
PKG_OPTIONS_GROUP.arch=		all
#PKG_OPTIONS_GROUP.arch+=	all+alpha
PKG_OPTIONS_GROUP.arch+=	generic ice40 ecp5 # stable
# PKG_OPTIONS_GROUP.arch+=	gowin fpgainterchange machxo2 mistral # alpha

PKG_SUPPORTED_OPTIONS=		x11
PKG_SUGGESTED_OPTIONS=		ice40

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			ice40 generic ecp5

.if !empty(PKG_OPTIONS:Mall)
CMAKE_CONFIGURE_ARGS+=			-DARCH=all
PLIST.ice40=			yes
PLIST.ecp5=			yes
PLIST.generic=			yes
# .elif !empty(PKG_OPTIONS:Mall+alpha)
# CMAKE_CONFIGURE_ARGS+=			-DARCH=all+alpha
# PLIST.ice40=			yes
# PLIST.ecp5=			yes
# PLIST.generic=		yes
.elif !empty(PKG_OPTIONS:Mice40)
CMAKE_CONFIGURE_ARGS+=			-DARCH=ice40
PLIST.ice40=			yes
.elif !empty(PKG_OPTIONS:Mecp5)
CMAKE_CONFIGURE_ARGS+=			-DARCH=ecp5
PLIST.ecp5=			yes
.elif !empty(PKG_OPTIONS:Mgeneric)
CMAKE_CONFIGURE_ARGS+=			-DARCH=generic
PLIST.generic=			yes
# .elif !empty(PKG_OPTIONS:Mgowin)
# CMAKE_CONFIGURE_ARGS+=			-DARCH=gowin
# .elif !empty(PKG_OPTIONS:Mfpgainterchange)
# CMAKE_CONFIGURE_ARGS+=			-DARCH=fpga_interchange
# .elif !empty(PKG_OPTIONS:Mmachxo2)
# CMAKE_CONFIGURE_ARGS+=			-DARCH=machxo2
# .elif !empty(PKG_OPTIONS:Mmistral)
# CMAKE_CONFIGURE_ARGS+=			-DARCH=mistral
.endif


# Using the PLIST.xyzzy variables below is a slightly hacky way of
# easily checking if a particular target is being built.
#
# This simply avoids duplicating the TOOL_DEPENDS lines in the "all"
# and "all+alpha" .if sections above.

.if "${PLIST.ice40}" == "yes"
TOOL_DEPENDS+=			icestorm-[0-9]*:../../wip/icestorm-git
.endif

.if "${PLIST.ecp5}" == "yes"
TOOL_DEPENDS+=			${PYPKGPREFIX}-prjtrellis-[0-9]*:../../wip/prjtrellis
.endif

###
### Build with the QT5 GUI
###
.if !empty(PKG_OPTIONS:Mx11)
CMAKE_CONFIGURE_ARGS+=			-DBUILD_GUI=ON
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif
