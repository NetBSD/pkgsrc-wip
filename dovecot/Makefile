# $NetBSD: Makefile,v 1.5 2003/05/06 22:34:55 lsed Exp $
#

DISTNAME=	dovecot-0.99.9.1
CATEGORIES=	mail
MASTER_SITES=	http://dovecot.procontrol.fi/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	freebsd.patch fetch.patch

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://dovecot.procontrol.fi/
COMMENT=	Secure IMAP and POP3 server

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL= YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-ssl=openssl

.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

PLIST_SRC=	${WRKDIR}/PLIST ${PKGDIR}/PLIST

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	# Generate modules part of PLIST dynamically.  It can be different
	# depending on OS.
	cd ${PREFIX} && ${FIND} libexec/dovecot -type f > ${WRKDIR}/PLIST

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
