# $NetBSD: Makefile,v 1.7 2005/05/24 10:31:44 rillig Exp $

DISTNAME=		sysklogd-1.4.1
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/daemons/}
MASTER_SITES+=		http://www.infodrom.org/projects/sysklogd/download/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.infodrom.org/projects/sysklogd/
COMMENT=		System and kernel log daemons for Linux

ONLY_FOR_PLATFORM=	Linux-*-*	# This has Linux klogd

USE_TOOLS+=		gmake
CFLAGS+=		-D_PATH_LOGCONF='\"${PKG_SYSCONFBASE}/syslog.conf\"'
MAKE_ENV+=		DESTDIR=${PREFIX} ROOT_GROUP=${ROOT_GROUP} \
			ROOT_USER=${ROOT_USER}
PKGMANDIR?=		man
MAKE_ENV+=		PKGMANDIR=${PKGMANDIR}

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		syslogd klogd
CONF_FILES+=		${PREFIX}/share/examples/sysklogd/syslog.conf ${PKG_SYSCONFDIR}/syslog.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sysklogd
	${INSTALL_DATA}	${FILESDIR}/syslog.conf ${PREFIX}/share/examples/sysklogd/
	${INSTALL_DATA} ${WRKSRC}/syslog.conf ${PREFIX}/share/examples/sysklogd/syslog.conf.example

.include "../../mk/bsd.pkg.mk"
