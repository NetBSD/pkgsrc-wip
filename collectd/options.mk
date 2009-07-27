PKG_OPTIONS_VAR=                PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=          rrdtool curl libstatgrab snmp
PKG_SUGGESTED_OPTIONS+=         rrdtool curl libstatgrab
.include "../../mk/bsd.options.mk"

#rrdtool
.if !empty(PKG_OPTIONS:Mrrdtool)
.include "../../databases/rrdtool/buildlink3.mk"
#CONFIGURE_ARGS+=    --with-librrd=${BUILDLINK_PREFIX.rrdtool}
CONFIGURE_ARGS+=    --enable-rrdtool
.endif

#curl
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#CONFIGURE_ARGS+=    --with-libcurl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=    --enable-curl
.endif

#libstatgrab
.if !empty(PKG_OPTIONS:Mlibstatgrab)
.include "../../devel/libstatgrab/buildlink3.mk"
CONFIGURE_ARGS+=    --with-libstatgrab=${BUILDLINK_PREFIX.libstatgraph}
.endif

#snmp
.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
#CONFIGURE_ARGS+=    --with-libsnmp=${BUILDLINK_PREFIX.net-snmp}
CONFIGURE_ARGS+=    --enable-snmp
.endif
