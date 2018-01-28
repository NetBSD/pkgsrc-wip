# $NetBSD: options.mk,v 1.6 2015/06/07 14:24:48 yrmt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libgda4				# XXX libgda4, to have mk.conf options on a per libgda basis.
PKG_SUPPORTED_OPTIONS=		bdb jdbc ldap mdb mysql postgres web
PKG_SUPPORTED_OPTIONS+=		json
PKG_SUPPORTED_OPTIONS+=		crypto						# XXX some wrong
#PKG_SUPPORTED_OPTIONS+=	bdbsql oracle				# XXX todo
PKG_SUPPORTED_OPTIONS+=		fam gui ui xslt

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# providers

.if !empty(PKG_OPTIONS:Mbdb)
PKGCONFIG_OVERRIDE+=	libgda-bdb-4.0.pc.in
BDB_ACCEPTED=		db5						# XXX db4
BDB_DEFAULT=		db5						# XXX User-settable but needed
CFLAGS+=		-I${PREFIX}/include/db5
BUILD_DIRS+=		providers/bdb
CONFIGURE_ARGS+=	--with-bdb=${PREFIX}				# XXX BDBBASE

SUBST_CLASSES+=		bdb
SUBST_STAGE.bdb=	post-patch
SUBST_FILES.bdb=	providers/bdb/Makefile.in
SUBST_SED.bdb=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.bdb=	"Fixing BDB prefix."

.include "../../mk/bdb.buildlink3.mk"
PLIST.bdb=		yes
.endif

.if !empty(PKG_OPTIONS:Mjdbc)
PKGCONFIG_OVERRIDE+=	libgda-jdbc-4.0.pc.in
PKG_JVMS_ACCEPTED=	openjdk7					# XXX openjdk7-bin sun-jdk6 a.o. (patch-ad and patch-fb)
BUILD_ENV+=		JAVA_HOME=${PKG_JAVA_HOME}
BUILD_DIRS+=		providers/jdbc
CONFIGURE_ARGS+=	--with-java=yes

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-patch
SUBST_FILES.java=	configure providers/jdbc/Makefile.in
SUBST_SED.java+=	-e "s|@JAVA_HOME@|${PKG_JAVA_HOME}|g"
SUBST_MESSAGE.java=	"Fixing configure and Java provider Makefile.in."

PLIST.jdbc=		yes
.  include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--with-java=no
.endif

.if !empty(PKG_OPTIONS:Mldap)
PKGCONFIG_OVERRIDE+=	libgda-ldap-4.0.pc.in
BUILD_DIRS+=		providers/ldap
CONFIGURE_ARGS+=	--with-ldap=${PREFIX}
.  include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--with-ldap=NO
.endif

.if !empty(PKG_OPTIONS:Mmdb)
PKGCONFIG_OVERRIDE+=	libgda-mdb-4.0.pc.in
BUILD_DIRS+=		providers/mdb
CONFIGURE_ARGS+=	--with-mdb=${PREFIX}
CFLAGS+=		-DMDB_WITH_WRITE_SUPPORT

SUBST_CLASSES+=		mdb
SUBST_STAGE.mdb=	post-patch
SUBST_FILES.mdb=	providers/mdb/Makefile.in
SUBST_SED.mdb=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.mdb=	"Fixing MDB provider Makefile.in."

.  include "../../wip/mdbtools/buildlink3.mk"
PLIST.mdb=		yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PKGCONFIG_OVERRIDE+=	libgda-mysql-4.0.pc.in
BUILD_DIRS+=		providers/mysql
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}				# XXX MYSQL_PREFIX conform mk/pgsql.buildlink3.mk
.  include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.endif

.if !empty(PKG_OPTIONS:Mpostgres)
PKGCONFIG_OVERRIDE+=	libgda-postgres-4.0.pc.in
BUILD_DIRS+=		providers/postgres
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX}
.  include "../../mk/pgsql.buildlink3.mk"
PLIST.postgres=		yes
.else
CONFIGURE_ARGS+=	--with-postgres=NO
.endif

.if !empty(PKG_OPTIONS:Mweb)
PKGCONFIG_OVERRIDE+=	libgda-web-4.0.pc.in
BUILD_DIRS+=		providers/web
CONFIGURE_ARGS+=	--with-web=${PREFIX}
.  include "../../mk/pgsql.buildlink3.mk"
PLIST.web=		yes
.endif

# various

#CONFIGURE_ARGS+=	--enable-introspection=yes			# XXX
#.include "../../devel/gobject-introspection/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mjson)
CONFIGURE_ARGS+=	--enable-json
.  include "../../textproc/json-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mui) || !empty(PKG_OPTIONS:Mgui)
PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.gui_ui

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons
	${CP} ${DESTDIR}${PREFIX}/share/libgda-4.0/pixmaps/gda-control-center.png ${DESTDIR}${PREFIX}/share/icons
	# XXX needed for gnumeric-1.10.17nb5
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include/libgda-4.0/libgda/control-center
	${INSTALL_DATA} ${WRKSRC}/control-center/gdaui-login-dialog.h ${DESTDIR}/${PREFIX}/include/libgda-4.0/libgda/control-center

.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgui)
.  include "../../graphics/goocanvas/buildlink3.mk"
.  include "../../graphics/graphviz/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxslt)
PKGCONFIG_OVERRIDE+=	libgda-xslt-4.0.pc.in
.  include "../../textproc/libxslt/buildlink3.mk"
PLIST.xslt=		yes
.endif

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
DEPENDS+=	p5-XML-Parser>=:../../textproc/p5-XML-Parser
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
