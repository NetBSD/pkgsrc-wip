# $NetBSD: Makefile,v 1.1.1.1 2009/03/24 15:42:29 bubuchka Exp $
#

DISTNAME=	nuttcp-${NUTTCP_VERSION}
CATEGORIES=	wip benchmarks
MASTER_SITES=	http://www.lcp.nrl.navy.mil/nuttcp/ \
		ftp://ftp.lcp.nrl.navy.mil/pub/nuttcp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.lcp.nrl.navy.mil/nuttcp/
COMMENT=	Network performance measurement tool, successor of nttcp

NUTTCP_VERSION=	6.1.2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	${PREFIX}/bin \
			${PREFIX}/${PKGMANDIR}/man8 \
			${PREFIX}/share/doc/${PKGBASE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nuttcp-${NUTTCP_VERSION} \
			${PREFIX}/bin/nuttcp
		${INSTALL_MAN} ${WRKSRC}/nuttcp.8 \
			${PREFIX}/${PKGMANDIR}/man8
		${INSTALL_DATA} ${WRKSRC}/README \
			${PREFIX}/share/doc/${PKGBASE}
		${INSTALL_DATA} ${WRKSRC}/examples.txt \
			${PREFIX}/share/doc/${PKGBASE}
		${INSTALL_DATA} ${WRKSRC}/nuttcp.html \
			${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
