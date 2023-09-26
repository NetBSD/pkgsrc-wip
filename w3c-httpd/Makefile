# $NetBSD$

DISTNAME=	w3c-httpd-3.0A
CATEGORIES=	www
MASTER_SITES=	https://www.w3.org/Daemon/httpd/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://www.w3.org/Daemon
COMMENT=	CERN httpd
LICENSE=	mit

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR} # TODO: one of All Daemon Library server_root, or leave it as-is

post-extract:

do-build:
	cd ${WRKSRC} && gmake CFLAGS="-DGOT_READ_DIR" LFLAGS="-lcrypt" RULE_FILE="${PREFIX}/etc/httpd.conf" BINDIR="${PREFIX}/bin"
	cd ${WRKSRC} && mkdir ${WRKSRC}/.destdir/${PREFIX}/lib
	cd ${WRKSRC} && mkdir ${WRKSRC}/.destdir/${PREFIX}/bin
	cd ${WRKSRC} && mkdir ${WRKSRC}/.destdir/${PREFIX}/etc
	cd ${WRKSRC} && cp Library/netbsd/libwww.a ${WRKSRC}/.destdir/${PREFIX}/lib
	cd ${WRKSRC} && cp Daemon/netbsd/cgiparse ${WRKSRC}/.destdir/${PREFIX}/bin
	cd ${WRKSRC} && cp Daemon/netbsd/cgiutils ${WRKSRC}/.destdir/${PREFIX}/bin
	cd ${WRKSRC} && cp Daemon/netbsd/htadm ${WRKSRC}/.destdir/${PREFIX}/bin
	cd ${WRKSRC} && cp Daemon/netbsd/htimage ${WRKSRC}/.destdir/${PREFIX}/bin
	cd ${WRKSRC} && cp Daemon/netbsd/httpd ${WRKSRC}/.destdir/${PREFIX}/bin
	${CP} ${FILESDIR}/httpd.conf ${WRKSRC}/.destdir/${PREFIX}/etc

print-PLIST:
	@${ECHO} @comment $$\NetBSD$$
	@cd ${WRKSRC}/.destdir/${PREFIX} && find * -type f | grep -vE "^etc\/"

do-install:
	mkdir -p ${PREFIX}/lib ${PREFIX}/bin ${PREFIX}/etc
	cd ${WRKSRC} && ${INSTALL_LIB} Library/netbsd/libwww.a ${PREFIX}/lib/
	cd ${WRKSRC} && ${INSTALL_PROGRAM} Daemon/netbsd/cgiparse ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_PROGRAM} Daemon/netbsd/cgiutils ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_PROGRAM} Daemon/netbsd/htadm ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_PROGRAM} Daemon/netbsd/htimage ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_PROGRAM} Daemon/netbsd/httpd ${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/httpd.conf ${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
