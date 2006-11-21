# $NetBSD: Makefile,v 1.1.1.1 2006/11/21 14:26:07 bartoszkuzma Exp $
#

DISTNAME=		smtp-gated-1.4.14-rc1
PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		mail
MASTER_SITES=		http://smtp-proxy.klolik.org/files/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://smtp-proxy.klolik.org/
COMMENT=		Proxy for SMTP sessions with virus and spam scan

SMTP_GATED_GROUP?=	smtpgw
SMTP_GATED_USER?=	smtpgw

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
SUBST_SED.conf=		-e 's,@SMTP_GATED_GROUP@,${SMTP_GATED_GROUP},g'
SUBST_SED.conf+=	-e 's,@SMTP_GATED_USER@,${SMTP_GATED_USER},g'
SUBST_SED.conf+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_STAGE.conf=	post-patch

DOCDIR=			${PREFIX}/share/doc/smtp-gated
EGDIR=			${PREFIX}/share/examples/smtp-gated
CONF_FILES=		${EGDIR}/smtp-gated.conf \
			${PKG_SYSCONFDIR}/smtp-gated.conf
RCD_SCRIPTS=		smtp_gated

USE_TOOLS+=		aclocal autoconf autoheader automake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nat

post-extract:
	${CP} ${FILESDIR}/smtp-gated.conf ${WRKDIR}

pre-configure:
	cd ${WRKSRC}; aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.PL ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/smtp-gated.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
