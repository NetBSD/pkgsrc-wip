# $NetBSD: Makefile,v 1.3 2012/10/03 17:57:30 asau Exp $
#

DISTNAME=	nuttcp-${NUTTCP_VERSION}
CATEGORIES=	benchmarks net
MASTER_SITES=	http://nuttcp.net/nuttcp/ \
		http://www.lcp.nrl.navy.mil/nuttcp/ \
		ftp://ftp.lcp.nrl.navy.mil/pub/nuttcp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.lcp.nrl.navy.mil/nuttcp/
COMMENT=	Network performance measurement tool, successor of nttcp

NUTTCP_VERSION=	6.1.2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/${PKGBASE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nuttcp-${NUTTCP_VERSION} \
			${DESTDIR}${PREFIX}/bin/nuttcp
		${INSTALL_MAN} ${WRKSRC}/nuttcp.8 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
		${INSTALL_DATA} ${WRKSRC}/README \
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
		${INSTALL_DATA} ${WRKSRC}/examples.txt \
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
		${INSTALL_DATA} ${WRKSRC}/nuttcp.html \
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
