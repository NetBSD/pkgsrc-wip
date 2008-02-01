# $NetBSD: options.mk,v 1.1.1.1 2008/02/01 03:23:42 jdwhite Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.ups-nut
PKG_SUPPORTED_OPTIONS+=	ups-nut-cgi ups-nut-snmp ups-nut-usb
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mups-nut-cgi)
CONFIGURE_ARGS+=	--with-cgi
CONFIGURE_ARGS+=	--with-cgipath=${NUT_CGIDIR:Q}
CONFIGURE_ARGS+=	--with-htmlpath=${PREFIX}/share/httpd/htdocs/nut
PLIST_SRC+=		${.CURDIR}/PLIST.cgi
CONF_FILES+=		${NUT_EGDIR}/upsstats-single.html.sample	\
			${NUT_CONFDIR}/upsstats-single.html
CONF_FILES+=		${NUT_EGDIR}/upsstats.html.sample		\
			${NUT_CONFDIR}/upsstats.html
CONF_FILES_PERMS+=	${NUT_EGDIR}/hosts.conf.sample 			\
			${NUT_CONFDIR}/hosts.conf 			\
			${ROOT_USER} ${ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsset.conf.sample 		\
			${NUT_CONFDIR}/upsset.conf 			\
			${ROOT_USER} ${ROOT_GROUP} 0600
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cgi
.endif

.if !empty(PKG_OPTIONS:Mups-nut-snmp)
CONFIGURE_ARGS+=	--with-snmp
PLIST_SRC+=		${.CURDIR}/PLIST.snmp
.include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.if !empty(PKG_OPTIONS:Mups-nut-usb)
CONFIGURE_ARGS+=	--with-usb=auto
.include "../../devel/libusb/buildlink3.mk"
PLIST_SRC+=		${.CURDIR}/PLIST.usb
.else
CONFIGURE_ARGS+=	--without-usb
.endif
