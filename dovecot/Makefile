# $NetBSD: Makefile,v 1.4 2003/05/06 21:13:27 lsed Exp $
#

DISTNAME=	dovecot-0.99.9.1
CATEGORIES=	mail
MASTER_SITES=	http://dovecot.procontrol.fi/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://dovecot.procontrol.fi/
COMMENT=	Secure IMAP and POP3 server

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL= YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-ssl=openssl

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

RCD_SCRIPTS=	dovecot

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
