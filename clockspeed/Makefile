# $NetBSD: Makefile,v 1.2 2006/05/04 16:19:36 akihabara Exp $

DISTNAME=	clockspeed-0.62
CATEGORIES=	time
MASTER_SITES=	http://cr.yp.to/clockspeed/

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://cr.yp.to/clockspeed.html
COMMENT=	Suite of clock synchronization utilities

WRKSRC=		${WRKDIR}/${DISTNAME}
CMDDIR=		${WRKSRC}
DOCDIR=		${WRKSRC}
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CLOCKSPEEDDIR=	/var/${PKGBASE}

DJB_RESTRICTED= YES
DJB_CONFIG_PREFIX= ${CLOCKSPEEDDIR}

DOCS=		${WRKSRC}/BLURB ${WRKSRC}/CHANGES ${WRKSRC}/README \
		${WRKSRC}/INSTALL ${WRKSRC}/TODO ${WRKSRC}/THANKS
USER_CMDS=	${CMDDIR}/clockview \
		${CMDDIR}/sntpclock ${CMDDIR}/taiclock ${CMDDIR}/taiclockd
SYS_CMDS=	${CMDDIR}/clockspeed ${CMDDIR}/clockadd
CONF_FILES=	${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

INSTALLATION_DIRS= ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 \
		${PKGMANDIR}/man8 ${EGDIR} bin

post-extract:
	${CP} ${.CURDIR}/files/leapsecs.dat ${WRKSRC}
	${MV} ${DOCDIR}/clockspeed.1 ${DOCDIR}/clockspeed.1.orig
	${SED} -e 's:/usr/local/clockspeed:${CLOCKSPEEDDIR}:' \
		${DOCDIR}/clockspeed.1.orig > ${DOCDIR}/clockspeed.1
	${CP} ${DOCDIR}/leapsecs.3 ${DOCDIR}/leapsecs.3.orig
	${SED} -e 's:/etc/:${PKG_SYSCONFDIR}/:' ${DOCDIR}/leapsecs.3.orig \
		> ${DOCDIR}/leapsecs.3
	${CP} ${WRKSRC}/leapsecs_read.c ${WRKSRC}/leapsecs_read.c.orig
	${SED} -e 's:/etc/:${PKG_SYSCONFDIR}/:' ${WRKSRC}/leapsecs_read.c.orig \
		> ${WRKSRC}/leapsecs_read.c

do-install:
	${MV} ${DOCDIR}/clockadd.1 ${DOCDIR}/clockadd.8
	${MV} ${DOCDIR}/clockspeed.1 ${DOCDIR}/clockspeed.8
	${INSTALL_PROGRAM} ${USER_CMDS} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${PREFIX}/sbin
	${INSTALL_MAN} ${DOCDIR}/*.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DOCDIR}/*.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${DOCDIR}/*.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PKGDOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} leapsecs.dat ${EGDIR}
	${INSTALL_DATA_DIR} ${CLOCKSPEEDDIR}
	${INSTALL_DATA_DIR} ${CLOCKSPEEDDIR}/etc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
