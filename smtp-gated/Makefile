# $NetBSD: Makefile,v 1.7 2012/10/07 16:23:15 asau Exp $
#

DISTNAME=		smtp-gated-1.4.18.8
# PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		mail
MASTER_SITES=		http://smtp-proxy.klolik.org/files/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://smtp-proxy.klolik.org/
COMMENT=		Proxy for SMTP sessions with virus and spam scan
LICENSE=		gnu-gpl-v2

SMTP_GATED_GROUP?=	smtpgw
SMTP_GATED_USER?=	smtpgw

BUILD_DEFS+=		VARBASE

BUILD_DEFS+=		SMTP_GATED_GROUP SMTP_GATED_USER
FILES_SUBST+=		SMTP_GATED_GROUP=${SMTP_GATED_GROUP:Q}
FILES_SUBST+=		SMTP_GATED_USER=${SMTP_GATED_USER:Q}

PKG_GROUPS=		${SMTP_GATED_GROUP}
PKG_USERS=		${SMTP_GATED_USER}:${SMTP_GATED_GROUP}

FILES_SUBST+=		SMTP_GATED_GROUP=${SMTP_GATED_GROUP:Q}
FILES_SUBST+=		SMTP_GATED_USER=${SMTP_GATED_USER:Q}
MESSAGE_SUBST+=		SMTP_GATED_GROUP=${SMTP_GATED_GROUP:Q}

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	${WRKDIR}/smtp-gated.conf
SUBST_VARS.conf=	SMTP_GATED_GROUP
SUBST_VARS.conf+=	SMTP_GATED_USER
SUBST_VARS.conf+=	VARBASE
SUBST_STAGE.conf=	post-patch

DOCDIR=			${PREFIX}/share/doc/smtp-gated
EGDIR=			${PREFIX}/share/examples/smtp-gated
CONF_FILES=		${EGDIR}/smtp-gated.conf \
			${PKG_SYSCONFDIR}/smtp-gated.conf
RCD_SCRIPTS=		smtp_gated
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes

post-extract:
	${CP} ${FILESDIR}/smtp-gated.conf ${WRKDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.PL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/smtp-gated.conf ${DESTDIR}${EGDIR}

.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
