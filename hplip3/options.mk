# $NetBSD: options.mk,v 1.3 2010/08/30 15:39:24 gregoire Exp $
#
# HPLIP dependencies are detailed in the following page:
# http://hplipopensource.com/hplip-web/install/manual/distros/other.html
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hplip
PKG_SUPPORTED_OPTIONS=	fax scan gui
PKG_SUGGESTED_OPTIONS=	fax scan

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		fax scan gui

.if !empty(PKG_OPTIONS:Mfax)
PLIST.fax=		yes
CONFIGURE_ARGS+=	--enable-fax-build
CONFIGURE_ARGS+=	--enable-dbus-build
EGFILES+=		cups/pstotiff.convs cups/pstotiff.types
MAKE_DIRS+=		${PKG_SYSCONFDIR}/cups
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus-build
CONFIGURE_ARGS+=	--disable-fax-build
.endif

.if !empty(PKG_OPTIONS:Mscan)
PLIST.scan=		yes
CONFIGURE_ARGS+=	--enable-scan-build
MESSAGE_SRC+=		MESSAGE.scan
MESSAGE_SUBST+=		EGDIR=${EGDIR}
DEPENDS+=	xsane-[0-9]*:../../graphics/xsane
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-scan-build
.endif

.if !empty(PKG_OPTIONS:Mgui)
PLIST.gui=		yes
CONFIGURE_ARGS+=	--enable-gui-build
CONFIGURE_ARGS+=	--enable-qt4
CONFIGURE_ARGS+=	--enable-policykit
EGFILES+=		dbus-1/system.d/com.hp.hplip.conf
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-policykit
CONFIGURE_ARGS+=	--disable-qt4
CONFIGURE_ARGS+=	--disable-gui-build
.endif
