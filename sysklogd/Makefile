# $NetBSD: Makefile,v 1.5 2004/04/09 07:50:22 jeremy-c-reed Exp $

DISTNAME=		sysklogd-1.4.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/daemons/}
MASTER_SITES+=		http://www.infodrom.org/projects/sysklogd/download/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.infodrom.org/projects/sysklogd/
COMMENT=		System and kernel log daemons for Linux

ONLY_FOR_PLATFORM=	Linux-*-*	# This has Linux klogd

USE_GNU_TOOLS+=		make
CFLAGS+=		-D_PATH_LOGCONF='\"${PKG_SYSCONFBASE}/syslog.conf\"'
MAKE_ENV+=		DESTDIR=${PREFIX} ROOT_GROUP=${ROOT_GROUP} \
			ROOT_USER=${ROOT_USER}

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		syslogd klogd
CONF_FILES+=		${PREFIX}/share/examples/sysklogd/syslog.conf ${PKG_SYSCONFDIR}/syslog.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sysklogd
	${INSTALL_DATA}	${FILESDIR}/syslog.conf ${PREFIX}/share/examples/sysklogd/
	${INSTALL_DATA} ${WRKSRC}/syslog.conf ${PREFIX}/share/examples/sysklogd/syslog.conf.example

.include "../../mk/bsd.pkg.mk"
