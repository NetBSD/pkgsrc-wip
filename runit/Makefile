# $NetBSD: Makefile,v 1.13 2012/10/07 14:51:34 asau Exp $

DISTNAME=	runit-2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/runit/
COMMENT=	UNIX init scheme with service supervision

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
PKGEXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}

USE_TOOLS+=		pax
BUILD_DEFS+=            VARBASE
DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS= ${SERVICEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755

DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS package/TODO doc/*.html

INSTALLATION_DIRS=	${PKGMANDIR} ${PKGMANDIR}/man8 sbin share/examples/runit

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/etc && ${PAX} -rwppm . ${DESTDIR}${PKGEXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
