# $NetBSD: Makefile,v 1.1 2006/05/04 13:55:38 akihabara Exp $

DISTNAME=	clockspeed-0.62
CATEGORIES=	time
MASTER_SITES=	http://cr.yp.to/clockspeed/

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://cr.yp.to/clockspeed.html
COMMENT=	Suite of time utilities

WRKSRC=		${WRKDIR}/${DISTNAME}
CMDDIR=		${WRKSRC}
DOCDIR=		${WRKSRC}
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

NO_CONFIGURE=	YES
DJB_RESTRICTED= YES

DOCS=		${WRKSRC}/BLURB ${WRKSRC}/CHANGES ${WRKSRC}/README \
		${WRKSRC}/INSTALL ${WRKSRC}/TODO ${WRKSRC}/THANKS
USER_CMDS=	${CMDDIR}/clockspeed ${CMDDIR}/clockadd ${CMDDIR}/clockview \
		${CMDDIR}/sntpclock ${CMDDIR}/taiclock ${CMDDIR}/taiclockd
CONF_FILES=	${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

INSTALLATION_DIRS= ${PKGMANDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 \
		${EGDIR} bin

post-extract:
	${CP} ${WRKSRC}/leapsecs.3 ${WRKSRC}/leapsecs.3.orig
	${SED} -e 's:/etc/:${PKG_SYSCONFDIR}/:' ${WRKSRC}/leapsecs.3.orig \
		> ${WRKSRC}/leapsecs.3
	${CP} ${WRKSRC}/leapsecs_read.c ${WRKSRC}/leapsecs_read.c.orig
	${SED} -e 's:/etc/:${PKG_SYSCONFDIR}/:' ${WRKSRC}/leapsecs_read.c.orig \
		> ${WRKSRC}/leapsecs_read.c

do-install:
	${INSTALL_PROGRAM} ${USER_CMDS} ${PREFIX}/bin
	${INSTALL_MAN} ${DOCDIR}/*.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DOCDIR}/*.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA_DIR} ${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PKGDOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} leapsecs.dat ${EGDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
