# $NetBSD: options.mk,v 1.0 2024/12/02 15:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.polyorb
PKG_SUPPORTED_OPTIONS=		ap-corba ap-dsa ap-moma ap-aws \
				pp-giop pp-soap pp-srp pp-dns \
				cs-event cs-ir cs-naming cs-notification cs-time \
				gnatcoll
PKG_OPTIONS_OPTIONAL_GROUPS=	shared-libs openssl
PKG_OPTIONS_GROUP.shared-libs=	enable-shared-libs disable-shared-libs
PKG_OPTIONS_GROUP.openssl=	openssl builtin-openssl

.include "../../mk/bsd.fast.prefs.mk"

PKG_SUGGESTED_OPTIONS=	ap-corba ap-dsa ap-moma \
			pp-giop pp-soap pp-srp pp-dns \
			cs-event cs-ir cs-naming cs-notification cs-time \
			builtin-openssl gnatcoll

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-shared-libs)
CONFIGURE_ARGS+=			--enable-shared
CONFIGURE_ARGS+=			--with-gprbuild=gprbuild
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif
.if !empty(PKG_OPTIONS:Mdisable-shared-libs)
CONFIGURE_ARGS+=			--disable-shared
.endif
.if empty(PKG_OPTIONS:Menable-shared-libs) && empty(PKG_OPTIONS:Mdisable-shared-libs)
CONFIGURE_ARGS+=			--with-gprbuild=gprbuild
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif

.if !empty(PKG_OPTIONS:Mbuiltin-openssl)
USE_BUILTIN.openssl=	yes
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.elif !empty(PKG_OPTIONS:Mopenssl)
USE_BUILTIN.openssl=	no
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.else
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll)
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"
.include "../../wip/gnatcoll-core/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnatcoll
.endif

.if !empty(PKG_OPTIONS:Map-aws)
APP_PERSONALITIES+=	aws
.endif
.if !empty(PKG_OPTIONS:Map-corba)
APP_PERSONALITIES+=	corba
.endif
.if !empty(PKG_OPTIONS:Map-dsa)
APP_PERSONALITIES+=	dsa
.endif
.if !empty(PKG_OPTIONS:Map-moma)
APP_PERSONALITIES+=	moma
.endif

.if !empty(PKG_OPTIONS:Mpp-dns)
PROTOCOL_PERSONALITIES+=	dns
.endif
.if !empty(PKG_OPTIONS:Mpp-giop)
PROTOCOL_PERSONALITIES+=	giop
.endif
.if !empty(PKG_OPTIONS:Mpp-soap)
PROTOCOL_PERSONALITIES+=	soap
.endif
.if !empty(PKG_OPTIONS:Mpp-srp)
PROTOCOL_PERSONALITIES+=	srp
.endif

.if !empty(PKG_OPTIONS:Mcs-event)
CORBA_SERVICES+=	event
.endif
.if !empty(PKG_OPTIONS:Mcs-ir)
CORBA_SERVICES+=	ir
.endif
.if !empty(PKG_OPTIONS:Mcs-naming)
CORBA_SERVICES+=	naming
.endif
.if !empty(PKG_OPTIONS:Mcs-notification)
CORBA_SERVICES+=	notification
.endif
.if !empty(PKG_OPTIONS:Mcs-time)
CORBA_SERVICES+=	time
.endif
