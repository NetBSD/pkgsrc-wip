# $NetBSD: Makefile,v 1.3 2006/04/28 22:58:13 schmonz Exp $

DISTNAME=	socklog-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smarden.org/socklog/
COMMENT=	System and kernel logging services

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=		package/CHANGES package/COPYING package/README doc/*.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
