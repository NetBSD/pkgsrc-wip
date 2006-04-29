# $NetBSD: Makefile,v 1.4 2006/04/29 03:04:19 akihabara Exp $

DISTNAME=	socklog-2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smarden.org/socklog/
COMMENT=	System and kernel logging services

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=         ${WRKSRC}/command
DOCDIR=         ${WRKSRC}/doc
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

DJB_ERRNO_HACK=		NO
DJB_RESTRICTED=		NO
DJB_SLASHPACKAGE=	YES

DOCS=		package/CHANGES package/COPYING package/README doc/*.html
USER_CMDS=      ${CMDDIR}/tryto ${CMDDIR}/uncat
SYS_CMDS=       ${CMDDIR}/socklog ${CMDDIR}/socklog-check ${CMDDIR}/socklog-conf

do-install:
	${INSTALL_PROGRAM} ${USER_CMDS} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${SYS_CMDS} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PKGDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PKGDOCDIR}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
