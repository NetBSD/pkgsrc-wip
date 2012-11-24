# $NetBSD: Makefile,v 1.3 2012/11/24 10:28:54 kristerw Exp $
#

PKGVERSION=	1.0
DISTNAME=	cvsup-mirror
PKGNAME=	cvsup-mirror-${PKGVERSION}
MASTER_SITES=   # empty
DISTFILES=      # empty

CATEGORIES=	net

NO_BUILD=	yes

MAINTAINER=	bseklecki@noc.cfi.pgh.pa.us
HOMEPAGE=	http://localhost/
COMMENT=	Syslog-ng embodies the next generation of logging systems

USE_TOOLS+=	pkg-config pax

PKG_SYSCONFSUBDIR=	cvsup

PKG_DESTDIR_SUPPORT=	destdir

do-install:
	${INSTALL_DATA} ${FILESDIR}/update.sh ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${FILESDIR}/config.netbsd.conf ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${FILESDIR}/supfile-netbsd ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${FILESDIR}/supfile-freebsd ${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/sup
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/sup-client-scan
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/prefixes

DEPENDS+=            cvsup>=16.1.hnb2:../../devel/cvsup

.include "../../mk/bsd.pkg.mk"
