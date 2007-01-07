# $NetBSD: Makefile,v 1.3 2007/01/07 09:16:00 rillig Exp $

DISTNAME=	ipsvd-0.12.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/ipsvd/
COMMENT=	Internet protocol service daemons

WRKSRC=		${WRKDIR}/net/${DISTNAME}
CMDDIR=		${WRKSRC}/command
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

DJB_ERRNO_HACK=		NO
DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

DOCS=		package/CHANGES package/COPYING package/README doc/*.html

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/*.7 ${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${WRKSRC}/man/tcpsvd.8 ${WRKSRC}/man/udpsvd.8 \
		${WRKSRC}/man/ipsvd-cdb.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
