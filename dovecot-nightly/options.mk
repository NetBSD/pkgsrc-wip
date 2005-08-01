# $NetBSD: options.mk,v 1.2 2005/08/01 10:54:32 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	dovecot-pop3d gnutls inet6 ldap mysql pam pgsql sasl

.include "../../mk/bsd.options.mk"

###
### Build with pop3 server.
### XXX: PLIST correct?
###
.if !empty(PKG_OPTIONS:Mdovecot-pop3d)
CONFIGURE_ARGS+=	--with-pop3d
.else
CONFIGURE_ARGS+=	--without-pop3d
.endif

###
### Build with GNU TLS or OpenSSL as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mgnutls)
# XXX still true?
PKG_FAIL_REASON+=	"GNU TLS support is currently broken."
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

###
### MySQL support.
###
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../databases/mysql4-client/buildlink3.mk"
.endif

###
### PostgreSQL support.
###
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### LDAP directory support.
###
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

###
### IMAP-AUTH via SASL.
###
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
