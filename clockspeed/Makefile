# $NetBSD: Makefile,v 1.6 2013/01/21 15:18:00 schmonz Exp $

DISTNAME=	clockspeed-0.62
CATEGORIES=	time
MASTER_SITES=	http://cr.yp.to/clockspeed/

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://cr.yp.to/clockspeed.html
COMMENT=	Suite of clock synchronization utilities
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${DISTNAME}
CMDDIR=		${WRKSRC}
DOCDIR=		${WRKSRC}
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CLOCKSPEEDDIR=	${VARBASE}/${PKGBASE}

DJB_RESTRICTED=		NO
DJB_CONFIG_PREFIX=	${CLOCKSPEEDDIR}

DOCS=		${WRKSRC}/BLURB ${WRKSRC}/CHANGES ${WRKSRC}/README \
		${WRKSRC}/INSTALL ${WRKSRC}/TODO ${WRKSRC}/THANKS
USER_CMDS=	${CMDDIR}/clockview \
		${CMDDIR}/sntpclock ${CMDDIR}/taiclock ${CMDDIR}/taiclockd
SYS_CMDS=	${CMDDIR}/clockspeed ${CMDDIR}/clockadd
CONF_FILES=	${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

INSTALLATION_DIRS=	${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 \
			${PKGMANDIR}/man8 ${EGDIR} bin sbin

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
	${INSTALL_PROGRAM} ${USER_CMDS} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${DOCDIR}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DOCDIR}/*.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${DOCDIR}/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} leapsecs.dat ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${CLOCKSPEEDDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${CLOCKSPEEDDIR}/etc

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
