# $NetBSD: Makefile,v 1.2 2008/09/07 16:37:03 pettai Exp $
#

DISTNAME=		sysmon-0.92.2
CATEGORIES=		net
MASTER_SITES=		ftp://puck.nether.net/pub/jared/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.sysmon.org/
COMMENT=		Small and fast network monitoring tool

GNU_CONFIGURE=		yes

BUILD_DEFS+=		IPV6_READY

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/sysmon
SMDOC=			${PREFIX}/share/doc/sysmon

CONF_FILES=		${EGDIR}/sysmon.conf.dist \
			${PKG_SYSCONFDIR}/sysmon.conf

INSTALLATION_DIRS=      share/examples/sysmon
INSTALLATION_DIRS+=     share/doc/sysmon bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/sysmon.conf.dist ${EGDIR}/sysmon.conf.dist
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg  ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt  ${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/sysmon.conf.man \
			${PREFIX}/${PKGMANDIR}/man5/sysmon.conf.5
	${INSTALL_DATA} ${WRKSRC}/docs/sysmon.man \
			${PREFIX}/${PKGMANDIR}/man8/sysmon.8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
