# $NetBSD: Makefile,v 1.4 2003/04/21 17:59:57 xtraeme Exp $
#

DISTNAME=	dancer-ircd-1.0.31+maint8-fn6
PKGNAME=	${DISTNAME:S/+maint8-fn6/m8/}
CATEGORIES=	chat
MASTER_SITES=	http://freenode.net/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://freenode.net/dancer_ircd.shtml
COMMENT=	Irc daemon based on hybrid ircd

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--with-config=dist

EGDIR=          ${PREFIX}/share/examples/dancer-ircd
DOCDIR=		${PREFIX}/share/doc/dancer-ircd

RCD_SCRIPTS=		dancer-ircd
PKG_SYSCONFSUBDIR=	dancer-ircd

CONF_FILES=	${EGDIR}/ircd.conf.default \
		${PKG_SYSCONFDIR}/ircd.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/hybrid
	(cd ${WRKSRC}/doc && \
	for f in RE* *.txt; do \
		${INSTALL_DATA} $$f ${DOCDIR}; done )
	( cd ${WRKSRC}/doc/hybrid/ && \
	for f in *; do \
		${INSTALL_DATA} $$f ${DOCDIR}/hybrid; done )
	${INSTALL_PROGRAM} ${WRKSRC}/src/dancer-ircd \
		${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkconf \
		${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install_ircd \
		${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/viconf \
		${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkpasswd \
		${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 \
		${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf \
		${PKG_SYSCONFDIR}/ircd.conf

.include "../../mk/bsd.pkg.mk"
