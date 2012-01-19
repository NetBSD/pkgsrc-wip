# $NetBSD: options.mk,v 1.2 2012/01/19 16:28:54 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgda4				# XXX libgda4, so i'm able to have mk.conf options on a per libgda basis.
PKG_SUPPORTED_OPTIONS=	mysql postgres
PKG_SUPPORTED_OPTIONS+=	bdb jdbc ldap					# XXX some wrong
#PKG_SUPPORTED_OPTIONS+=	bdbsql crypto mdb oracle sqlite web	# XXX todo
PKG_SUPPORTED_OPTIONS+=	fam gui ui

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# providers

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db5						# XXX db4
BDB_DEFAULT=		db5						# XXX User-settable but needed
CFLAGS+=		-I${PKG_JAVA_HOME}/include/db5
CFLAGS+=		-I${PREFIX}/include/db5
BUILD_DIRS+=		providers/bdb
CONFIGURE_ARGS+=	--with-bdb=yes	#${PREFIX}			# XXX BDBBASE
CONFIGURE_ARGS+=	--with-bdb-libdir-name=lib
.include "../../mk/bdb.buildlink3.mk"
PLIST.bdb=		yes
.endif

.if !empty(PKG_OPTIONS:Mjdbc)
PKG_JVMS_ACCEPTED= 	openjdk7					# XXX openjdk7-bin sun-jdk6 a.o. (patch-ad)
BUILD_DIRS+=		providers/jdbc
CONFIGURE_ARGS+=	--with-java=${PKG_JAVA_HOME}
CONFIGURE_ARGS+=	--with-jni=${PKG_JAVA_HOME}/include/netbsd	# XXX linux a.o.
.  include "../../mk/java-vm.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
BUILD_DIRS+=		providers/ldap
CONFIGURE_ARGS+=	--with-ldap=${PREFIX}
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
BUILD_DIRS+=		providers/mysql
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}				# XXX MYSQL_PREFIX conform mk/pgsql.buildlink3.mk
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.endif

.if !empty(PKG_OPTIONS:Mpostgres)
BUILD_DIRS+=		providers/postgres
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}
.include "../../mk/pgsql.buildlink3.mk"
PLIST.postgres=		yes
.endif

# various

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mui) || !empty(PKG_OPTIONS:Mgui)
PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.gui_ui
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgui)
.  include "../../graphics/goocanvas/buildlink3.mk"
.  include "../../graphics/graphviz/buildlink3.mk"
.endif
