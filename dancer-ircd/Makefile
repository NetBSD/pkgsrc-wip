# $NetBSD: Makefile,v 1.2 2003/04/20 17:34:40 xtraeme Exp $
#

DISTNAME=	dancer-ircd-1.0.31+maint8
PKGNAME=	${DISTNAME:S/+maint/m/}
CATEGORIES=	chat
MASTER_SITES=	http://www.doc.ic.ac.uk/~aps100/dancer/dancer-ircd/stable/releases/

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

.include "../../mk/bsd.pkg.mk"
