# $NetBSD: Makefile,v 1.9 2005/08/01 10:51:31 thomasklausner Exp $

DISTNAME=		dovecot-${_DOVECOT_VER}
PKGNAME=		dovecot-nightly-${_DOVECOT_VER}
CATEGORIES=		mail
MASTER_SITES=		http://dovecot.fi/nightly/

MAINTAINER=		tom@replic8.net
HOMEPAGE=		http://dovecot.fi/
COMMENT=		Secure, full-featured IMAP (and POP3) server

NO_CHECKSUM=		YES

CONFLICTS=		dovecot

USE_LIBTOOL=		YES
USE_PKGINSTALL= 	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=/var \
			--with-ssldir=${SSLCERTS} \
			--without-shadow \
			--with-passwd \
			--without-passwd-file \
			--without-bsdauth \

WRKSRC=			${WRKDIR}/dovecot-1.0-test77

# for ${DATE}
.include "../../mk/bsd.prefs.mk"

_DOVECOT_VER!=		${DATE} +%Y%m%d

.include "options.mk"

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
