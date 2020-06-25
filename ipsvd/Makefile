# $NetBSD: Makefile,v 1.8 2013/03/23 08:37:36 shattered Exp $

DISTNAME=	ipsvd-1.0.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/ipsvd/
COMMENT=	Internet protocol service daemons

WRKSRC=		${WRKDIR}/net/${DISTNAME}
CMDDIR=		${WRKSRC}/command
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

SUBST_CLASSES+=		djberrno

DOCS=		package/CHANGES package/COPYING package/README doc/*.html

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man7 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/*.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${WRKSRC}/man/tcpsvd.8 ${WRKSRC}/man/udpsvd.8 \
		${WRKSRC}/man/ipsvd-cdb.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
