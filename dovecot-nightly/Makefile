# $NetBSD: Makefile,v 1.3 2004/03/05 06:40:47 xtraeme Exp $

DISTNAME=		dovecot-${_DOVECOT_VER}
PKGNAME=		dovecot-nightly-${_DOVECOT_VER}
CATEGORIES=		mail
MASTER_SITES=		http://dovecot.fi/nightly/

MAINTAINER=		tom@replic8.net
HOMEPAGE=		http://dovecot.fi/
COMMENT=		Secure, full-featured IMAP (and POP3) server

NO_CHECKSUM=		YES

CONFLICTS=		dovecot

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL= 	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=/var \
			--with-ssldir=${SSLCERTS}

WRKSRC=			${WRKDIR}/dovecot-0.99.11-test4

.include "../../mk/bsd.prefs.mk"

_DOVECOT_VER!=		${DATE} +%Y%m%d

BUILD_DEFS+=		DOVECOT_USE_GNUTLS DOVECOT_USE_PGSQL	\
			USE_INET6 USE_OPENLDAP USE_SASL2

.if defined(DOVECOT_USE_MBOX) && !empty(DOVECOT_USE_MBOX:M[Yy][Ee][Ss]) && defined(DOVECOT_USE_MAILDIR) && !empty(DOVECOT_USE_MAILDIR:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-storages=maildir,mbox
.elif defined(DOVECOT_USE_MBOX) && !empty(DOVECOT_USE_MBOX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-storages=mbox
.elif defined(DOVECOT_USE_MAILDIR) && !empty(DOVECOT_USE_MAILDIR:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-storages=maildir
.else
CONFIGURE_ARGS+=	--with-storages=maildir,mbox
.endif

.if defined(USE_PAM) && !empty(USE_PAM:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=        --without-pam
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if defined(USE_SASL2) && !empty(USE_SASL2:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif

.if defined(DOVECOT_USE_POP3D) && !empty(DOVECOT_USE_POP3D:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pop3d
.else
CONFIGURE_ARGS+=        --without-pop3d
.endif

.if !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../databases/postgresql-lib/buildlink3.mk"
.endif

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

post-configure:
	@cd ${WRKSRC};							\
	for ${FILE} in dovecot-example.conf; do				\
		${SED} ${FILES_SUBST_SED} $$file > $$file.new;		\
		${MV} -f $$file.new $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
