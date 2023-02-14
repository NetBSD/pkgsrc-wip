# $NetBSD$

PROGNAME=	confkerndev
VERS=		0.0.1

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=0xDRRB/}
GITLAB_TAG=	c04ed5bd08d4f79e06edefbb3a43b7f80307f0e5

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://gitlab.com/0xDRRB/confkerndev/
COMMENT=	Command line tool to disable drivers in binary kernel file
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${PROGNAME}-${GITLAB_TAG}

USE_LANGUAGES+=	c

BUILD_TARGET=	all

.include "options.mk"

PLIST_VARS+=	build32
.if !empty(PKG_OPTIONS:Mbuild32)
PLIST.build32=	yes
.endif

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}${PREFIX}/sbin/${PROGNAME}
.if !empty(PKG_OPTIONS:Mbuild32)
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME}i386 ${DESTDIR}${PREFIX}/sbin/${PROGNAME}i386
.endif

.include "../../mk/bsd.pkg.mk"
