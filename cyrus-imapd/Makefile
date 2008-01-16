# $NetBSD: Makefile,v 1.9 2008/01/16 14:57:03 obache Exp $

DISTNAME=	cyrus-imapd-2.3.11
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/imap/ \
		http://www.t.ring.gr.jp/archives/net/mail/cyrus-mail/ \
		ftp://ftp.t.ring.gr.jp/pub/net/mail/cyrus-mail/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://cyrusimap.web.cmu.edu/imapd/
COMMENT=	Cyrus IMAP server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
BDB_ACCEPTED=		db4 db3

BUILD_DEFS+=		VARBASE

CHECK_PORTABILITY_SKIP=	configure.lineno

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER:Q}
FILES_SUBST+=		CYRUS_GROUP=${CYRUS_GROUP:Q}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER:Q}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP:Q}
CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/cyrus-master.pid
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ENV+=		ac_cv_lib_wrap_request_init=yes

CONFIGURE_ARGS+=	--enable-idled
CONFIGURE_ARGS+=	--enable-listext
CONFIGURE_ARGS+=	--enable-murder
CONFIGURE_ARGS+=	--enable-nntp
CONFIGURE_ARGS+=	--enable-replication
CONFIGURE_ARGS+=	--without-ucdsnmp

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi kerberos kerberos4 ldap zephyr
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
CRYPTO+=		uses Kerberos encryption code
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
COMERRBASE=		${KRB5BASE}
.else
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST_SUBST+=		LDAP=
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUBST+=		LDAP="@comment "
.endif

.if !empty(PKG_OPTIONS:Mzephyr)
.  include "../../chat/zephyr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zephyr=${BUILDLINK_PREFIX.zephyr}
PLIST_SUBST+=		LDAP=
.else
CONFIGURE_ARGS+=	--without-zephyr
PLIST_SUBST+=		LDAP="@comment "
.endif

.if exists(/usr/bin/compile_et)
COMERRBASE?=		/usr
.endif
.if defined(COMERRBASE)
.  if exists(${COMERRBASE}/include/krb5/com_err.h)
CPPFLAGS+=		-I${COMERRBASE}/include/krb5
.  endif
CONFIGURE_ENV+=		COMPILE_ET=${COMERRBASE}/bin/compile_et
.else
CONFIGURE_ARGS+=	--with-com-err=yes
.endif

MAKE_ENV+=		PERL=${PERL5:Q}

HTMLDIR=		${PREFIX}/share/doc/cyrus-imapd
EGDIR=			${PREFIX}/share/examples/cyrus-imapd
CONF_FILES=		${EGDIR}/imapd.conf ${PKG_SYSCONFDIR}/imapd.conf
CONF_FILES+=		${EGDIR}/normal.conf ${PKG_SYSCONFDIR}/cyrus.conf
RCD_SCRIPTS=		cyrus
FILES_SUBST+=		IMAPDCONF=${PKG_SYSCONFDIR}/imapd.conf

PERL5_PACKLIST= \
	auto/Cyrus/IMAP/.packlist			\
	auto/Cyrus/SIEVE/managesieve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# NetBSD's libssl is built without bn/bn_const.c
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DOPENSSL_LACK_BN_CONST
.endif

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

CONFIGURE_ENV+=	BDB_TYPE=${BDB_TYPE:Q}

# Only imap/mupdate needs to be build with pthreads support, so selectively
# enable it via patches for just that one program.
#
.include "../../mk/pthread.buildlink3.mk"

# Change references of some manpages from foo.8 to cyrus-foo.8 to avoid
# manpage conflicts with other packages.  Also change references to
# "/etc/{cyrus,imapd}.conf" into "${PKG_SYSCONFDIR}/{cyrus,imapd}.conf".
#
post-patch:
	cd ${WRKSRC}/man;						\
	set --	deliver 8 fetchnews 8 idled 8 imapd 8 lmtpd 8 master 8	\
		nntpd 8	notifyd 8 pop3d 8 quota 8;			\
	while [ $$# -gt 0 ]; do						\
		man=$$1.$$2;						\
		for file in Makefile.in *.[0-9]; do			\
			sed	-e "s|\(\$$(srcdir)/\)\($$man\)|\1cyrus-\2|g" \
				-e "s|\(\\\fB\)\($$1($$2)\\\fR\)|\1cyrus-\2|g" \
				$$file > $$file.fixed;			\
			mv -f $$file.fixed $$file;			\
		done;							\
		if [ -f $$man ]; then					\
			mv $$man cyrus-$$man;			\
		fi;							\
		shift 2;						\
	done
	find ${WRKSRC} -type f -print |					\
	xargs -n 1 ${GREP} -l -e /etc/imapd\.conf -e /etc/cyrus\.conf | \
	while read file; do						\
		sed	-e "s|/etc/\(cyrus\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			-e "s|/etc/\(imapd\.conf\)|${PKG_SYSCONFDIR}/\1|g" \
			$${file} > $${file}.fixed;			\
		mv -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/migrate-metadata ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mknewsgroups ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/translatesieve ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rehash ${DESTDIR}${PREFIX}/cyrus/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/master/conf; for file in *.conf; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${EGDIR};		\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc; for file in *.html cyrusv2.mc; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${HTMLDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
