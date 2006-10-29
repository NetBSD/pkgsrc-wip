# $NetBSD: Makefile,v 1.19 2006/10/29 08:32:42 shattered Exp $
#

DISTNAME=	ezbounce-1.04c
CATEGORIES=	chat
MASTER_SITES=	http://druglord.freelsd.org/ezbounce/		\
		http://www.shellcentral.com/downloads/files/	\
		http://ezbounce.dc-team.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://druglord.freelsd.org/ezbounce/
COMMENT=	Highly Configurable IRC Proxy

GNU_CONFIGURE=	YES

USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-ssl

EGDIR=		${PREFIX}/share/examples/ezbounce
DOCDIR=		${PREFIX}/share/doc/ezbounce

EZBOUNCE_USER=		ezbounce
EZBOUNCE_GROUP=		ezbounce

PKG_GROUPS=		${EZBOUNCE_GROUP}
PKG_USERS=		${EZBOUNCE_USER}:${EZBOUNCE_GROUP}::Ezbounce\ user

RCD_SCRIPTS=		ezbounce

CONF_FILES=	${EGDIR}/ezbounce.conf.default ${PKG_SYSCONFDIR}/ezbounce.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${WRKSRC}/mdidentd/mdidentd \
		${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezbchk ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ezb.conf ${EGDIR}/ezbounce.conf.default
	${INSTALL_DATA} ${WRKSRC}/misc/ezbounce.1 ${PREFIX}/${PKGMANDIR}/man1
	( cd ${WRKSRC} && for f in README* TODO CHANGES sample.conf sample.MOTD; do \
		${INSTALL_DATA} $$f ${DOCDIR}; \
	done )

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
