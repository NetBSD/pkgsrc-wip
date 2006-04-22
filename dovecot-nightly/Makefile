# $NetBSD: Makefile,v 1.16 2006/04/22 10:48:36 rillig Exp $

DISTNAME=		dovecot-${DOVECOT_VER}
PKGNAME=		${DISTNAME:S/-/-nightly-/}
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/nightly/

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# generate WRKSRC on demand
WRKSRC_CMD=		${ECHO} ${WRKDIR}/dovecot-1.0*
WRKSRC=			${WRKSRC_CMD:sh}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-ssldir=${SSLCERTS:Q}

.include "../../mk/bsd.prefs.mk"

DOVECOT_VER_CMD=	${SETENV} TZ=UTC ${DATE} +%Y%m%d
DOVECOT_VER?=		${DOVECOT_VER_CMD:sh}
CONFLICTS+=		dovecot-[0-9]*
NO_CHECKSUM=		yes
NO_SRC_ON_FTP=		fetch from real master site only

.include "options.mk"

RCD_SCRIPTS=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
PKG_GROUPS=		${DOVECOT_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\ IMAP/POP3\ user

EGDIR=			${PREFIX}/share/examples/dovecot
CONF_FILES=		${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot		\
			share/examples/dovecot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	dovecot-example.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	pre-configure

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
