# $NetBSD$

PROGNAME=	chkugenids
VERS=		0.2

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=0xDRRB/}
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://gitlab.com/0xDRRB/chkugenids/
COMMENT=	Command line tool to get info on USB device through /dev/ugenN.EE
LICENSE=	2-clause-bsd


WRKSRC=		${WRKDIR}/${PROGNAME}-v${VERS}

USE_LANGUAGES+=	c

EGDIR=		${PREFIX}/share/examples/chkugenids

INSTALLATION_DIRS=	sbin ${EGDIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}${PREFIX}/sbin/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/04-NFCsetperm ${DESTDIR}${EGDIR}/04-NFCsetperm

.include "../../mk/bsd.pkg.mk"
