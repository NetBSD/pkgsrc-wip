# $NetBSD: options.mk,v 1.1 2014/01/18 19:13:53 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=	cpu df interface load memory perl python swap syslog
PKG_SUGGESTED_OPTIONS+=	cpu df interface load memory swap syslog

.if ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=	contextswitch pf tcpconns uptime users
PKG_SUGGESTED_OPTIONS+=	contextswitch pf tcpconns uptime users
.endif

.if ${OPSYS} == "FreeBSD"
PKG_SUPPORTED_OPTIONS+=	contextswitch pf processes tcpconns uptime zfs-arc
PKG_SUGGESTED_OPTIONS+=	contextswitch pf processes tcpconns uptime zfs-arc
.endif

.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	apple-sensors battery contextswitch disk processes	\
			tcpconns uptime users
PKG_SUGGESTED_OPTIONS+=	apple-sensors battery contextswitch disk processes	\
			tcpconns uptime users
.endif

.if ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	disk nfs uptime users zfs-arc
PKG_SUGGESTED_OPTIONS+=	disk nfs uptime users zfs-arc
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		apple-sensors battery contextswitch cpu df disk		\
			interface load memory nfs perl pf python swap syslog	\
			tcpconns uptime users zfs-arc

.for option in ${PLIST_VARS}
.  if !empty(PKG_OPTIONS:M${option})
CONFIGURE_ARGS+=	--enable-${option:S/-/_/}
PLIST.${option}=	yes
.  endif
.endfor

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
PERL5_PACKLIST+=	auto/Collectd/.packlist
CONFIGURE_ARGS+=	--with-libperl=${BUILDLINK_PREFIX.perl5}
CONFIGURE_ARGS+=	--with-perl-bindings=${MAKE_PARAMS:Q}
.  include "../../lang/perl5/module.mk"
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
.  include "../../lang/python/application.mk"
.endif
