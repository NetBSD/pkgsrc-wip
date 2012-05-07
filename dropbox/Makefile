# $NetBSD: Makefile,v 1.1.1.1 2012/05/07 00:02:38 thomasklausner Exp $
#

DISTNAME=	dropbox-lnx.x86-1.4.0
PKGNAME=	dropbox-1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dl-web.dropbox.com/u/17/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dropbox.com/
COMMENT=	Dropbox sync server
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

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
