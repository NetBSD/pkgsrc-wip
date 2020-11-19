# $NetBSD: Makefile,v 1.6 2013/03/21 17:34:50 shattered Exp $

DISTNAME=	uschedule-0.7.1
CATEGORIES=	time
MASTER_SITES=	http://www.ohse.de/uwe/uschedule/

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	https://www.ohse.de/uwe/uschedule.html
COMMENT=	Secure management of job scheduling

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command
DOCDIR=		${WRKSRC}/doc
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

DJB_SLASHPACKAGE=	YES
NO_CONFIGURE=		YES

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS=	${SERVICEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755

DOCS=		${DOCDIR}/ChangeLog ${DOCDIR}/NEWS ${DOCDIR}/SECURITY-BUG
USER_CMDS=	${CMDDIR}/uschedule ${CMDDIR}/uschedulecmd \
		${CMDDIR}/uscheduleconf ${CMDDIR}/uschedulecp \
		${CMDDIR}/uscheduleedit ${CMDDIR}/uschedulelist \
		${CMDDIR}/uschedulerm ${CMDDIR}/uscheduleruntimelimit
SYS_CMDS=	${CMDDIR}/uscheduled

INSTALLATION_DIRS=	${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man7 \
			${PKGMANDIR}/man8 bin sbin

do-install:
	${INSTALL_PROGRAM} ${USER_CMDS} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${DOCDIR}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DOCDIR}/*.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${DOCDIR}/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
