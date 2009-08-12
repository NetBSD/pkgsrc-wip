# $NetBSD: Makefile,v 1.1.1.1 2009/08/12 20:03:07 shindenmorr Exp $
#

DISTNAME=	haproxy-1.3.20
CATEGORIES=	www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.3/src/

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://haproxy.1wt.eu/download/1.3/src/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
PKG_DESTDIR_SUPPORT=	user-destdir
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
RCD_SCRIPTS=		haproxy
INSTALLATION_DIRS+=	share/examples/rc.d
.endif

.if ${OPSYS} == "NetBSD"
TARGET=netbsd
.elif ${OPSYS} == "FreeBSD"
TARGET=freebsd
.elif ${OPSYS} == "OpenBSD"
TARGET=openbsd
.elif ${OPSYS} == "Linux"
.if !empty(OS_VERSION:M2.6.*)
TARGET=linux26
.elif !empty(OS_VERSION:M2.4.*)
.if exists(/usr/include/linux/eventpoll.h)
TARGET=linux24e
.else
TARGET=linux24
.endif
.endif
.else
TARGET=generic
.endif

do-build:
	cd ${WRKSRC} && make TARGET=${TARGET}

do-install:
	cd ${WRKSRC} && make PREFIX=${DESTDIR}${PREFIX} \
	DOCDIR=${DESTDIR}${PREFIX}/share/doc/${PKGBASE} \
	MANDIR=${DESTDIR}${PREFIX}/man install

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg ${DESTDIR}${EGDIR};

.include "../../mk/bsd.pkg.mk"
