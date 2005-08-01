# $NetBSD: Makefile,v 1.10 2005/08/01 15:02:47 tvierling Exp $

DISTNAME=		dovecot-${DOVECOT_VER}
PKGNAME=		${DISTNAME:S/-/-nightly-/}
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/nightly/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# generate WRKSRC on demand
WRKSRC_CMD=		${ECHO} ${WRKDIR}/dovecot-1.0-test*
WRKSRC=			${WRKSRC_CMD:sh}

USE_LIBTOOL=		yes
USE_PKGINSTALL= 	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ssldir=${SSLCERTS}

.include "../../mk/bsd.prefs.mk"

DOVECOT_VER_CMD=	${DATE} +%Y%m%d
DOVECOT_VER?=		${DOVECOT_VER_CMD:sh}
CONFLICTS+=		dovecot-[0-9]*
NO_CHECKSUM=		yes
NO_SRC_ON_FTP+=		"fetch from real master site only"

.include "options.mk"

RCD_SCRIPTS=	dovecot
DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot		\
			share/examples/dovecot

post-configure:
	@cd ${WRKSRC};							\
	for i in dovecot-example.conf; do				\
		${SED} ${FILES_SUBST_SED} $$i > $$i.new;		\
		${MV} -f $$i.new $$i;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
