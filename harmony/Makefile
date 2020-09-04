# $NetBSD: Makefile,v 1.26 2017/01/16 14:06:43 mef Exp $

GITHUB_TAG=	a7bb5a65b71644d9efce5fed783ed545b9336548
GITHUB_PROJECT=	harmony
DISTNAME=	harmony-${GITHUB_TAG}
PKGNAME=	harmony-0.0.20181014
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bugzilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bugzilla.org/
COMMENT=	Web based bug tracking system
LICENSE=	mpl-2.0

DEPENDS+=	ap2[0-9]-perl-[0-9]*:../../www/ap2-perl
DEPENDS+=	p5-Mojolicious-[0-9]*:../../wip/p5-Mojolicious
DEPENDS+=	p5-Mojolicious-Plugin-OAuth2-Server-[0-9]*:../../www/p5-Mojolicious-Plugin-OAuth2-Server
DEPENDS+=	p5-MojoX-Log-Log4perl-Tiny-[0-9]*:../../wip/p5-MojoX-Log-Log4perl-Tiny
DEPENDS+=	p5-Mojo-JWT-[0-9]*:../../wip/p5-Mojo-JWT
DEPENDS+=	p5-FFI-Platypus-[0-9]*:../../wip/p5-FFI-Platypus
DEPENDS+=	p5-DBIx-Connector-[0-9]*:../../databases/p5-DBIx-Connector
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Email-Send-[0-9]*:../../mail/p5-Email-Send
DEPENDS+=	p5-Email-MIME-[0-9]*:../../mail/p5-Email-MIME
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Math-Random-ISAAC-[0-9]*:../../math/p5-Math-Random-ISAAC
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Chart-[0-9]*:../../graphics/p5-Chart
DEPENDS+=	libwww-[0-9]*:../../www/libwww
DEPENDS+=	p5-Template-GD-[0-9]*:../../graphics/p5-Template-GD
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
DEPENDS+=	p5-PatchReader-[0-9]*:../../devel/p5-PatchReader
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=	p5-Net-SMTP-SSL-[0-9]*:../../mail/p5-Net-SMTP-SSL
DEPENDS+=	p5-RadiusPerl-[0-9]*:../../net/p5-RadiusPerl
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-XMLRPC-Lite-[0-9]*:../../net/p5-XMLRPC-Lite
DEPENDS+=	p5-JSON-RPC-[0-9]*:../../www/p5-JSON-RPC
DEPENDS+=	p5-Test-Taint-[0-9]*:../../devel/p5-Test-Taint
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber-[0-9]*:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-Encode-Detect-[0-9]*:../../textproc/p5-Encode-Detect
DEPENDS+=	p5-Email-Reply-[0-9]*:../../mail/p5-Email-Reply
DEPENDS+=	p5-HTML-FormatText-WithLinks-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks
DEPENDS+=	p5-TheSchwartz-[0-9]*:../../devel/p5-TheSchwartz
DEPENDS+=	p5-Daemon-Generic-[0-9]*:../../sysutils/p5-Daemon-Generic
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Cache-Memcached-[0-9]*:../../devel/p5-Cache-Memcached
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Sereal-[0-9]*:../../converters/p5-Sereal
DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Algorithm-BloomFilter-[0-9]*:../../math/p5-Algorithm-BloomFilter
DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Crypt-OpenPGP-[0-9]*:../../security/p5-Crypt-OpenPGP
DEPENDS+=	p5-Crypt-SMIME-[0-9]*:../../security/p5-Crypt-SMIME
DEPENDS+=	p5-Devel-NYTProf-[0-9]*:../../devel/p5-Devel-NYTProf
DEPENDS+=	p5-Data-Password-passwdqc-[0-9]*:../../security/p5-Data-Password-passwdqc
DEPENDS+=	p5-Text-CSV_XS-[0-9]*:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-URI-Escape-XS-[0-9]*:../../www/p5-URI-Escape-XS
DEPENDS+=	p5-HTML-Escape-[0-9]*:../../www/p5-HTML-Escape
DEPENDS+=	p5-Taint-Util-[0-9]*:../../devel/p5-Taint-Util
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-CGI-Compile-[0-9]*:../../www/p5-CGI-Compile
DEPENDS+=	p5-Cache-Memcached-Fast-[0-9]*:../../devel/p5-Cache-Memcached-Fast
DEPENDS+=	p5-Email-MIME-Attachment-Stripper-[0-9]*:../../mail/p5-Email-MIME-Attachment-Stripper
DEPENDS+=	p5-JSON-RPC-[0-9]*:../../www/p5-JSON-RPC
DEPENDS+=	Text-MultiMarkdown-[0-9]*:../../textproc/p5-MultiMarkdown
DEPENDS+=	p5-MooX-StrictConstructor-[0-9]*:../../devel/p5-MooX-StrictConstructor
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Search-Elasticsearch-[0-9]*:../../devel/p5-Search-Elasticsearch

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=	pax perl:run
NO_BUILD=	YES

BZ_WEB_GROUP?=	${APACHE_GROUP}
SENDMAIL?=	/usr/sbin/sendmail
CVS?=		/usr/bin/cvs

BUILD_DEFS+=	SENDMAIL CVS APACHE_USER APACHE_GROUP

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	BZ_WEB_GROUP APACHE_GROUP

MESSAGE_SUBST+=	BZDIR=${BZDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

BZDIR=			${PREFIX}/share/bugzilla
EGDIR=			${PREFIX}/share/examples/bugzilla
DOCDIR=			${PREFIX}/share/doc/bugzilla
CONF_FILES=		${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf
CONF_FILES_PERMS=	${EGDIR}/localconfig ${BZDIR}/localconfig \
			${APACHE_USER} ${SHAREGRP} 0400

REPLACE_PERL+=		*.pl *.cgi docs/makedocs.pl

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	bugzilla.conf localconfig Bugzilla/BugMail.pm
SUBST_VARS.conf=	BZ_WEB_GROUP
SUBST_VARS.conf+=	PREFIX
SUBST_VARS.conf+=	BZDIR
SUBST_VARS.conf+=	CVS
SUBST_VARS.conf+=	DBDRIVER
SUBST_SED.conf+=	-e "s|/usr/lib/sendmail|${SENDMAIL}|g"

SUBST_CLASSES+=		diff
SUBST_STAGE.diff=	post-configure
SUBST_MESSAGE.diff=	Fixing diff path used for Patch Viewer (Ignore depending on OS)
SUBST_FILES.diff=	localconfig
SUBST_SED.diff=		-e "s|\$diffpath = .*|\$diffpath = \'${DIFF}\';|" -e "s|/diff||"

INSTALLATION_DIRS+=	${DOCDIR} ${DOCDIR}/en ${EGDIR} ${BZDIR} ${BZDIR}/Bugzilla
INSTALLATION_DIRS+=	${BZDIR}/js ${BZDIR}/lib ${BZDIR}/template ${BZDIR}/skins
INSTALLATION_DIRS+=	${BZDIR}/docs ${BZDIR}/docs/en ${BZDIR}/docs/en/html
INSTALLATION_DIRS+=	${BZDIR}/images ${BZDIR}/docs/en/html/api
INSTALLATION_DIRS+=	${BZDIR}/docs/en/html/api/Bugzilla
.for i in data contrib t xt template lib graphs skins
INSTALLATION_DIRS+=	${BZDIR}/${i}
.endfor

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		BZDIR=${BZDIR}

do-configure:
	(cd ${WRKSRC}; ./checksetup.pl)

post-extract:
	${CP} ${FILESDIR}/bugzilla.conf	${WRKSRC}
	${CP} ${FILESDIR}/localconfig	${WRKSRC}

do-install:

.for i in ${BZDIR} ${EGDIR} ${DOCDIR} ${BZDIR}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${i}
.endfor
	(cd ${WRKSRC}					    ;\
	pax -rw -pmp docs		${DESTDIR}${BZDIR} ;\
	${INSTALL_SCRIPT} *.cgi *.pl	${DESTDIR}${BZDIR}  ;\
	${INSTALL_SCRIPT} robots.txt	${DESTDIR}${BZDIR}  ;\
	${INSTALL_DATA} Bugzilla.pm	${DESTDIR}${BZDIR}  ;\
	${INSTALL_DATA} README		${DESTDIR}${DOCDIR} ;\
	${INSTALL_DATA} localconfig	${DESTDIR}${EGDIR}  ;\
	${INSTALL_DATA} bugzilla.conf	${DESTDIR}${EGDIR}  ;\
	${INSTALL_DATA} images/*.png	${DESTDIR}${BZDIR}/images  ;\
	${INSTALL_DATA} images/favicon.ico	${DESTDIR}${BZDIR} ;\
	pax -rw -pmp Bugzilla		${DESTDIR}${BZDIR}  ;\
	pax -rw -pmp js			${DESTDIR}${BZDIR}  ;\
	pax -rw -pmp template		${DESTDIR}${BZDIR} ;\
	)

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
