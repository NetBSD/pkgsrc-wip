# $NetBSD: Makefile,v 1.1 2006/04/25 13:31:09 akihabara Exp $

DISTNAME=	uschedule-0.7.1
CATEGORIES=	time
MASTER_SITES=	http://www.ohse.de/uwe/uschedule/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ohse.de/uwe/uschedule.html
COMMENT=	Secure management of job scheduling.

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command
DOCDIR=		${WRKSRC}/doc

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS= ${SERVICEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
DOCS=		${DOCDIR}/ChangeLog ${DOCDIR}/NEWS ${DOCDIR}/SECURITY-BUG
USER_CMDS=	${CMDDIR}/uschedule ${CMDDIR}/uschedulecmd \
		${CMDDIR}/uscheduleconf ${CMDDIR}/uschedulecp \
		${CMDDIR}/uscheduleedit ${CMDDIR}/uschedulelist \
		${CMDDIR}/uschedulerm ${CMDDIR}/uscheduleruntimelimit
SYS_CMDS=	${CMDDIR}/uscheduled

INSTALLATION_DIRS= ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man7 \
		${PKGMANDIR}/man8 sbin

post-patch:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/src/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${USER_CMDS} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${PREFIX}/sbin
	${INSTALL_MAN} ${DOCDIR}/*.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DOCDIR}/*.7 ${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${DOCDIR}/*.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PKGDOCDIR}

.include "../../mk/bsd.pkg.mk"
