# $NetBSD: Makefile,v 1.1.1.1 2003/05/07 23:32:33 jeremy-c-reed Exp $

DISTNAME=		sysklogd-1.4.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/daemons/}
MASTER_SITES+=		http://www.infodrom.org/projects/sysklogd/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.infodrom.org/projects/sysklogd/
COMMENT=		System and kernel log daemons for Linux

ONLY_FOR_PLATFORM=	Linux-*-*	# This has Linux klogd

USE_GMAKE=		YES
CFLAGS+=		-D_PATH_LOGCONF='\"${PKG_SYSCONFBASE}/syslog.conf\"'
MAKE_ENV+=		DESTDIR=${PREFIX} ROOT_GROUP=${ROOT_GROUP} \
			ROOT_USER=${ROOT_USER}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sysklogd
	${INSTALL_DATA} ${WRKSRC}/syslog.conf ${PREFIX}/share/examples/sysklogd/syslog.conf.example

.include "../../mk/bsd.pkg.mk"
