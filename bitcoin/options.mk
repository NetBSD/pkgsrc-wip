# $NetBSD$

# TODO: make qt optional, and support qt5
# TODO: create split package for qt gui

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=		qt4 miniupnpc dbus
PKG_SUGGESTED_OPTIONS+=		dbus

.include "../../mk/bsd.options.mk"

# This fails to work because rcc (/usr/pkg/bin/qt4/rcc) is not found
# by configure.  Until fixed, leave the option off.
.if !empty(PKG_OPTIONS:Mqt4)
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

# qrencode is only used by the qt gui, and it is tiny compared to qt.
.include "../../converters/qrencode/buildlink3.mk"

CONFIGURE_ARGS+=	--with-qt-bindir=${QTDIR}/bin

PLIST.qt4=	yes
.endif

.if !empty(PKG_OPTIONS:Mminiupnpc)
.include "../../wip/miniupnpc/buildlink3.mk"
.endif

# TODO: Add a comment explaining what this does, and decide if it
# should just be enabled instead of being an option.
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif
