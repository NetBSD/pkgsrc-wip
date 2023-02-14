# $NetBSD$

PROGNAME=	findugendev
VERS=		0.0.1

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=0xDRRB/}
GITLAB_TAG=	a407eea2600b0ff1f13a30d1b6a0e8f03f25c7a8

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://gitlab.com/0xDRRB/findugendev/
COMMENT=	Command line tool to find the right /dev/ugenN.EE from USB device info
LICENSE=	2-clause-bsd


WRKSRC=		${WRKDIR}/${PROGNAME}-${GITLAB_TAG}

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}${PREFIX}/sbin/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
