# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:38 asau Exp $
#

DISTNAME=	dropbox-lnx.x86-1.4.0
PKGNAME=	dropbox-1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dl-web.dropbox.com/u/17/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/
COMMENT=	Dropbox sync server
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/.dropbox-dist
USE_LANGUAGES=	# none
USE_TOOLS=	pax

INSTALLATION_DIRS=	bin libexec/dropbox

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

do-build:
	(${ECHO} '#!/bin/sh'; \
	${ECHO} LD_LIBRARY_PATH=${PREFIX}/libexec/dropbox:'$$LD_LIBRARY_PATH'; \
	${ECHO} exec ${PREFIX}/libexec/dropbox/dropbox '"$$@"') > ${WRKSRC}/dropboxd

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${PREFIX}/libexec/dropbox
	mv ${DESTDIR}${PREFIX}/libexec/dropbox/dropboxd ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
