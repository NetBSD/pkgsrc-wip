# $NetBSD: Makefile,v 1.12 2004/05/07 01:57:52 xtraeme Exp $
#

DISTNAME=	ezbounce-1.04a
CATEGORIES=	chat
MASTER_SITES=	http://druglord.freelsd.org/ezbounce/ \
		http://www.shellcentral.com/downloads/files/

PATCHFILES=	ezb-1.04a-crash-fix-patch
PATCH_DIST_STRIP=	-p1
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://druglord.freelsd.org/ezbounce/
COMMENT=	Highly Configurable IRC Proxy

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--with-ssl

EGDIR=		${PREFIX}/share/examples/ezbounce
DOCDIR=		${PREFIX}/share/doc/ezbounce

EZBOUNCE_USER=		ezbounce
EZBOUNCE_GROUP=		ezbounce

PKG_GROUPS=             ${EZBOUNCE_GROUP}
PKG_USERS=		${EZBOUNCE_USER}:${EZBOUNCE_GROUP}::Ezbounce\\ user

RCD_SCRIPTS=            ezbounce

CONF_FILES=	${EGDIR}/ezbounce.conf.default ${PKG_SYSCONFDIR}/ezbounce.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${WRKSRC}/mdidentd/mdidentd \
		${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezbchk ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ezb.conf ${EGDIR}/ezbounce.conf.default
	${INSTALL_DATA} ${WRKSRC}/misc/ezbounce.1 ${PREFIX}/man/man1
	( cd ${WRKSRC} && for f in README* TODO CHANGES sample.conf sample.MOTD; do \
		${INSTALL_DATA} $$f ${DOCDIR}; \
	done )

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
