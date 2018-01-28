# $NetBSD: Makefile,v 1.7 2014/06/22 19:57:10 thomasklausner Exp $

DISTNAME=	openca-0.9.2.5
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openca/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pki.openca.org/
COMMENT=	Robust, full-featured out-of-the-box Certification Authority

DEPENDS+=	p5-Authen-SASL>=2.04:../../security/p5-Authen-SASL
DEPENDS+=	p5-CGI-Session>=3.95:../../www/p5-CGI-Session
DEPENDS+=	p5-Convert-ASN1>=0.17:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-MIME-Base64>=2.20:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Digest-SHA1>=2.02:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Digest-MD5>=2.24:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-IO-Socket-SSL>=0.92:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Lite>=3.01:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MailTools>=1.58:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-tools>=5.411:../../mail/p5-MIME-tools
DEPENDS+=	p5-Net-Server>=0.86:../../net/p5-Net-Server
DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-URI>=1.23:../../www/p5-URI
DEPENDS+=	p5-XML-Twig>=3.09:../../textproc/p5-XML-Twig
DEPENDS+=	p5-X500-DN>=0.28:../../net/p5-X500-DN
DEPENDS+=	p5-Locale-libintl>=1.10:../../misc/p5-Locale-libintl
DEPENDS+=	p5-perl-ldap>=0.33:../../databases/p5-perl-ldap


WRKSRC=		${WRKDIR}/${DISTNAME:S/openca/OpenCA/}
USE_TOOLS+=	perl:run pkg-config gmake
BUILD_DEFS+=	OPENCA_USER OPENCA_GROUP OPENCA_HOST APACHE_USER APACHE_GROUP \
		VARBASE

.include "../../mk/bsd.prefs.mk"
.include "Makefile.config"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKG_SYSCONFSUBDIR=	openca
OPENCA_USER?=		openca
OPENCA_GROUP?=		openca
OPENCA_HOST?=		localhost
BUILD_TARGET=		# empty
INSTALL_TARGET=		install-online install-ca
EGDIR=			${PREFIX}/share/examples/openca
DOCDIR=			${PREFIX}/share/doc/openca
MKDIRS=			access_control servers bp bp/functions database \
			init.d openssl openssl/openssl openssl/extfiles \
			rbac rbac/cmds scep
OWN_DIRS_PERMS+=	${VARBASE}/openca ${APACHE_USER} ${APACHE_GROUP} 0750
MESSAGE_SUBST+=		OPENCA_HOST=${OPENCA_HOST:Q} \
			PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
RCD_SCRIPTS=		openca

PKG_USERS=		${OPENCA_USER:Q}:${OPENCA_GROUP:Q}::OpenCA\ user
PKG_GROUPS=		${OPENCA_GROUP:Q}

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-lib-prefix=${PREFIX}/lib/openca
CONFIGURE_ARGS+=	--with-var-prefix=${VARBASE}/openca
CONFIGURE_ARGS+=	--with-etc-prefix=${EGDIR}
CONFIGURE_ARGS+=	--with-openca-prefix=${PREFIX}/share/openca
CONFIGURE_ARGS+=	--with-openca-user=${OPENCA_USER:Q}
CONFIGURE_ARGS+=	--with-openca-group=${OPENCA_GROUP:Q}
CONFIGURE_ARGS+=	--with-web-host=${OPENCA_HOST:Q}
CONFIGURE_ARGS+=	--with-httpd-user=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--with-httpd-group=${APACHE_GROUP:Q}
CONFIGURE_ARGS+=	--with-cgi-fs-prefix=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--with-htdocs-fs-prefix=${PREFIX}/share/httpd/htdocs
CONFIGURE_ARGS+=	--disable-external-modules

.for f in ${SERVERS}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${ROOT_USER} ${APACHE_GROUP:Q} 0644
EGFILES+=		${EGDIR}/${f}
.endfor

.for f in ${OPENCA_OPENCA}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${OPENCA_USER:Q} ${OPENCA_GROUP:Q} 0644
EGFILES+=		${EGDIR}/${f}
.endfor

.for f in ${WWW_WWW}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${APACHE_USER:Q} ${APACHE_GROUP:Q} 0644
EGFILES+=		${EGDIR}/${f}
.endfor

.for f in ${OPENCA_OPENCA_EX}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${OPENCA_USER:Q} ${OPENCA_GROUP:Q} 0755
EGFILES+=		${EGDIR}/${f}
.endfor

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	src/web-interfaces/batch/batch.conf \
			src/web-interfaces/ca/ca.conf \
			src/web-interfaces/ldap/ldap.conf \
			src/web-interfaces/node/node.conf \
			src/web-interfaces/ra/ra.conf
SUBST_SED.conf=		-e 's|@MYMAKE@|${MAKE:Q}|g'
SUBST_MESSAGE.conf=	Fixing configuration files.

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-install
SUBST_FILES.etc=	${EGFILES}
SUBST_SED.etc=		-e 's|${EGDIR}|${PKG_SYSCONFDIR}|g'
SUBST_MESSAGE.etc=	Fixing references to ${PKG_SYSCONFDIR}.

SUBST_CLASSES+=		cgi
SUBST_STAGE.cgi=	pre-install
SUBST_FILES.cgi=	src/web-interfaces/ca/ca \
			src/web-interfaces/ldap/ldap \
			src/web-interfaces/node/node \
			src/web-interfaces/pub/pki \
			src/web-interfaces/ra/RAServer \
			src/web-interfaces/scep/scep
SUBST_SED.cgi=		-e 's|${EGDIR}|${PKG_SYSCONFDIR}|g'
SUBST_MESSAGE.cgi=	Fixing references to ${PKG_SYSCONFDIR}.

post-install:
	cd ${WRKSRC}/src/scripts && ${SETENV} ${MAKE_ENV} ${MAKE} install
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} install-doc
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} install-man

.for f in ${MKDIRS}
		${MKDIR} ${PKG_SYSCONFDIR}/${f}
.endfor

	${CHOWN} ${OPENCA_USER}:${OPENCA_GROUP} \
		${PKG_SYSCONFDIR}/access_control
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/bp
	${CHOWN} ${OPENCA_USER}:${OPENCA_GROUP} ${PKG_SYSCONFDIR}/bp/functions
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/database
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/init.d
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/openssl
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
		${PKG_SYSCONFDIR}/openssl/extfiles
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
		${PKG_SYSCONFDIR}/openssl/openssl
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/rbac
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/rbac/cmds
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${PKG_SYSCONFDIR}/scep
	${CHOWN} ${OPENCA_USER}:${OPENCA_GROUP} ${PKG_SYSCONFDIR}/servers

	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/howto
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/errorcodes.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/howto/dartmouth.txt ${DOCDIR}/howto
	${INSTALL_DATA} ${WRKSRC}/docs/howto/wallus.txt ${DOCDIR}/howto

	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EGDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
