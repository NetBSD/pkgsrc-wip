# $NetBSD: Makefile,v 1.7 2006/04/28 22:46:23 schmonz Exp $

DISTNAME=	runit-1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/runit/
COMMENT=	UNIX init scheme with service supervision

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command

DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS= ${SERVICEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS package/TODO doc/*.html

INSTALLATION_DIRS=	${PKGMANDIR} ${PKGMANDIR}/man8 sbin share/examples/runit

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/etc && ${PAX} -rwppm . ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
