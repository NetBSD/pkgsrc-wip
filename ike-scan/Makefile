# $NetBSD: Makefile,v 1.2 2003/04/05 14:25:27 adrian_p Exp $
#

DISTNAME=	ike-scan-1.1
CATEGORIES=	security net
MASTER_SITES=	http://www.nta-monitor.com/ike-scan/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.nta-monitor.com/ike-scan/
COMMENT=	Discovers IKE hosts and can also fingerprint them

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/ike-scan

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ike-scan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ike-scan/
	${INSTALL_DATA} ${WRKSRC}/udp-backoff-fingerprinting-paper.txt \
		${PREFIX}/share/doc/ike-scan/

.include "../../mk/bsd.pkg.mk"
