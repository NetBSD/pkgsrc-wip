# $NetBSD: Makefile,v 1.16 2012/10/03 21:32:47 asau Exp $

DISTNAME=		openscep-0.4.2
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://openscep.othello.ch/download/

MAINTAINER=		carton@Ivy.NET
HOMEPAGE=		http://openscep.othello.ch/
COMMENT=		CA glue for Cisco SCEP

BUILD_DEPENDS+=		w3m>=0.5.1:../../www/w3m


.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		automake autoconf grep perl:run
OPENSCEP_USER?=		openscep
OPENSCEP_GROUP?=	openscep
PKG_GROUPS=		${OPENSCEP_USER}
PKG_USERS=		${OPENSCEP_USER}:${OPENSCEP_GROUP}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKG_SYSCONFSUBDIR?=	openscep # it installs more subdirectories under this
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-openscep-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=/openscep
CONFIGURE_ARGS+=	--with-cgi-dir=/cgi-bin/openscep
CONFIGURE_ARGS+=	--with-html-install-dir=${PREFIX}/share/httpd/htdocs/openscep
CONFIGURE_ARGS+=	--with-cgi-install-dir=${PREFIX}/libexec/cgi-bin/openscep
CONFIGURE_ARGS+=	--with-pkiclientexe=${PREFIX}/libexec/cgi-bin/pkiclient.exe
CONFIGURE_ARGS+=	--with-log-facility=LOG_DAEMON
CONFIGURE_ARGS+=	--with-caowner=${OPENSCEP_USER:Q}
CONFIGURE_ARGS+=	--with-cagroup=${OPENSCEP_GROUP:Q}
CONFIGURE_ARGS+=	--with-group=${APACHE_GROUP:Q}
CONFIGURE_ARGS+=	--with-user=${APACHE_USER:Q}
MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q} INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.openscep
PKG_SUPPORTED_OPTIONS=	openscep-web-ui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenscep-web-ui)
PLIST_SUBST+=		WEBUI=
MAKE_ENV+=		WEBUI=YES
.else
PLIST_SUBST+=		WEBUI="@comment "
MAKE_ENV+=		WEBUI=no
.endif

REPLACE_PERL+=		cgi-bin/pending.pl
REPLACE_PERL+=		cgi-bin/log.pl
REPLACE_PERL+=		cgi-bin/add.pl
REPLACE_PERL+=		cgi-bin/crl.pl
REPLACE_PERL+=		cgi-bin/granted.pl
REPLACE_PERL+=		cgi-bin/revoked.pl
REPLACE_PERL+=		cgi-bin/rejected.pl
REPLACE_PERL+=		cgi-bin/scep.pl

MESSAGE_SUBST+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}

EGDIR=			${PREFIX}/share/examples/openscep

CONF_FILES_PERMS+=	${EGDIR}/ldap-cheatsheet.sh ${PKG_SYSCONFDIR}/ldap-cheatsheet.sh ${BINOWN} ${BINGRP} ${BINMODE}
CONF_FILES_PERMS+=	${EGDIR}/openscep.cnf.example ${PKG_SYSCONFDIR}/openscep.cnf ${OPENSCEP_USER} ${APACHE_GROUP} 640
CONF_FILES+=		${EGDIR}/openscep.schema ${PKG_SYSCONFBASE}/openldap/schema/openscep.schema

OPENSCEP_CA_EXPIRY?=	3652
OPENSCEP_CERT_EXPIRY?=	366
OPENSCEP_CRL_EXPIRY?=	1

.for def in \
	OPENSCEP_USER OPENSCEP_GROUP APACHE_GROUP OPENSCEP_CA_EXPIRY
SETUPSH_SUBST+=	${def:Q}=${${def}:Q}
BUILD_DEFS+=	${def}
.endfor
.for def in \
	PREFIX SSLBASE CHOWN MKDIR CHMOD RM TOUCH SED GREP PKG_SYSCONFDIR
SETUPSH_SUBST+=	${def:Q}=${${def}:Q}
.endfor

SUBST_CLASSES+=		setupsh
SUBST_STAGE.setupsh=	pre-configure
SUBST_FILES.setupsh=	openssl/openscepsetup.in
SUBST_SED.setupsh=	${SETUPSH_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

# needed by openscep.cnf
.if ${:!hostname!:S/./ /g:[\#]} < 3
temp_OPENSCEP_LDAP_BASE=	nonce example org
.else
temp_OPENSCEP_LDAP_BASE=	${:!hostname!:S/./ /g}
.endif
OPENSCEP_LDAP_HOST?=		${temp_OPENSCEP_LDAP_BASE:ts.}
OPENSCEP_LDAP_BASE?=		${temp_OPENSCEP_LDAP_BASE:[2..-1]:S/^/dc=/:ts,}
.for def in \
	OPENSCEP_CERT_EXPIRY OPENSCEP_CRL_EXPIRY OPENSCEP_LDAP_BASE
CNF_SUBST+=			${def:Q}=${${def}:Q}
BUILD_DEFS+=			${def}
.endfor
CNF_SUBST+=			PREFIX=${PREFIX:Q}
CNF_SUBST+=			OPENSCEP_LDAP_HOST=${OPENSCEP_LDAP_HOST:Q}

SUBST_CLASSES+=		cnf
SUBST_STAGE.cnf=	pre-configure
SUBST_FILES.cnf=	openssl/openscep.cnf.in
SUBST_SED.cnf=		${CNF_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-configure:
	cd ${WRKSRC} && ${RM} -rf libltdl ltmain.sh ltconfig
#	cd ${WRKSRC} && libtoolize --ltdl -c -f
	cd ${WRKSRC} && libtoolize -c -f
	cd ${WRKSRC} && ${LN} -sf ${PREFIX}/share/automake-1.9/depcomp . # flame on, flaming piece of shit.  flame on.
	cd ${WRKSRC} && ${SETENV} LIBTOOLIZE=true autoreconf --force

post-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/ldap-cheatsheet.sh > ${WRKDIR}/ldap-cheatsheet.sh
	${INSTALL_SCRIPT} ${WRKDIR}/ldap-cheatsheet.sh ${EGDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
