# $NetBSD: Makefile,v 1.2 2003/05/27 12:00:15 xtraeme Exp $
#

DISTNAME=	ezbounce-1.02
CATEGORIES=	chat
MASTER_SITES=	http://druglord.freelsd.org/ezbounce/ \
		http://www.shellcentral.com/downloads/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://druglord.freelsd.org/ezbounce/
COMMENT=	Highly Configurable IRC Proxy

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--with-ssl

EGDIR=		${PREFIX}/share/examples/ezbounce
DOCDIR=		${PREFIX}/share/doc/ezbounce

RCD_SCRIPTS=            ezbounce

CONF_FILES=	${EGDIR}/ezbounce.conf.default ${PKG_SYSCONFDIR}/ezbounce.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezbchk ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${EGDIR}/ezbounce.conf.default
	${INSTALL_DATA} ${WRKSRC}/ezb.conf ${PKG_SYSCONFDIR}/ezbounce.conf
	${INSTALL_PROGRAM} ${WRKSRC}/mdidentd/mdidentd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/misc/ezbounce.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} &&	\
	for f in README* TODO CHANGES; do \
	${INSTALL_DATA} $$f ${DOCDIR}; done

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
