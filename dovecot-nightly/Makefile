# $NetBSD: Makefile,v 1.7 2004/08/08 18:05:47 kristerw Exp $

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

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=/var \
			--with-ssldir=${SSLCERTS} \
			--without-shadow \
			--with-passwd \
			--without-passwd-file \
			--without-bsdauth \

WRKSRC=			${WRKDIR}/dovecot-0.99.11-test4

_DOVECOT_VER!=		${DATE} +%Y%m%d

BUILD_DEFS+=		DOVECOT_USE_GNUTLS DOVECOT_USE_PGSQL	\
			USE_PAM USE_INET6 USE_OPENLDAP

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

.if defined(DOVECOT_USE_POP3D) && !empty(DOVECOT_USE_POP3D:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pop3d
.else
CONFIGURE_ARGS+=        --without-pop3d
.endif

.if defined(DOVECOT_USE_GNUTLS) && !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if defined(DOVECOT_USE_PGSQL) && !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

post-configure:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/dovecot-example.conf	\
		> ${WRKSRC}/dovecot-example.conf-new
	${MV} -f ${WRKSRC}/dovecot-example.conf-new ${WRKSRC}/dovecot-example.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
