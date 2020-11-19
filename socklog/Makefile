# $NetBSD: Makefile,v 1.10 2012/10/07 15:56:50 asau Exp $

DISTNAME=	socklog-2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/socklog/
COMMENT=	System and kernel logging services
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

DJB_SLASHPACKAGE=	YES

SUBST_CLASSES+=		djberrno

DOCS=		package/CHANGES package/COPYING package/README doc/*.html
USER_CMDS=	${CMDDIR}/tryto ${CMDDIR}/uncat
SYS_CMDS=	${CMDDIR}/socklog ${CMDDIR}/socklog-check ${CMDDIR}/socklog-conf

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${USER_CMDS} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
