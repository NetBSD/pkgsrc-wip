# $NetBSD: $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi kerberos kerberos4 ldap pcre
PKG_SUPPORTED_OPTIONS+=	mysql pgsql sqlite http
PKG_SUGGESTED_OPTIONS=	pcre http ldap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ldap http

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
.else
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
CHECK_BUILTIN.heimdal:=		yes
.  include "../../security/heimdal/buildlink3.mk"
CHECK_BUILTIN.heimdal:=		no
CHECK_BUILTIN.mit-krb5:=	yes
.  include "../../security/mit-krb5/buildlink3.mk"
CHECK_BUILTIN.mit-krb5:=	no
.  if ( ${USE_BUILTIN.heimdal:tl} == yes || \
	${USE_BUILTIN.mit-krb5:tl} == yes) && \
        exists(/usr/bin/compile_et) && exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=	-I/usr/include/krb5
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  elif ${OPSYS} != "Linux" && \
	exists(/usr/bin/compile_et) && exists(/usr/include/com_err.h)
CONFIGURE_ENV+=	COMPILE_ET=/usr/bin/compile_et
.  else
CONFIGURE_ARGS+=	--with-com-err=yes
.  endif
.endif
.if !empty(CONFIGURE_ENV:MCOMPILE_ET=*)
post-configure:		generate-compile-et
.endif

.PHONY: generate-compile-et
generate-compile-et:
	${RUN}cd ${WRKSRC}/com_err/et;				\
	if ${TEST} ! -f Makefile -a  ! -f compile_et; then	\
		${SED} 	-e 's,@SED@,${SED},g'			\
			-e 's,@AWK@,${AWK},g'			\
			-e 's,@DIR@,${WRKSRC}/com_err/et,g'	\
			< compile_et.sh > compile_et;		\
		${CHMOD} +x compile_et;				\
	fi

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if !empty(PKG_OPTIONS:Mhttp)
.  include "../../databases/sqlite3/buildlink3.mk"
.  include "../../textproc/libxml2/buildlink3.mk"
.  include "../../time/libical/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-http
CONFIGURE_ARGS+=        --with-sqlite=${BUILDLINK_PREFIX.sqlite3}
PLIST.http=		yes
.else
CONFIGURE_ARGS+=        --disable-http
.endif
