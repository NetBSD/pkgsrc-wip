# $NetBSD: Makefile,v 1.2 2003/09/30 09:11:28 hfath Exp $
# FreeBSD Id: ports/net/l2tpd/Makefile,v 1.6 2003/04/16 13:53:27 ru Exp

DISTNAME=	l2tpd-0.69
CATEGORIES=	net
MASTER_SITES=	http://www.l2tpd.org/downloads/

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://www.l2tpd.org/
COMMENT=	Implementation of the layer two tunneling protocol (l2tp)

USE_PKGINSTALL= YES

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=     l2tpd
DOCDIR=		${PREFIX}/share/doc/l2tpd
EGDIR=		${PREFIX}/share/examples/l2tpd
CONF_FILES=	${EGDIR}/l2tpd.conf.sample ${PKG_SYSCONFDIR}/l2tpd.conf
CONF_FILES+=	${EGDIR}/l2tpd-secrets.sample ${PKG_SYSCONFDIR}/l2tpd-secrets

post-patch:
	@cd ${WRKSRC}/doc && 							\
	for F in l2tpd.8 l2tpd.conf.sample l2tp-secrets.5 l2tpd.conf.5 ; do	\
		${MV} $${F} $${F}.orig; 					\
		${SED} -e 's|%%SYSCONFDIR%%|${PKG_SYSCONFDIR}|g' $${F}.orig > $${F}; 	\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l2tpd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/l2tp-secrets.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tpd.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tp-secrets.sample ${EGDIR}

.include "../../mk/bsd.pkg.mk"
