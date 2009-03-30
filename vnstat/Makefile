# $NetBSD: Makefile,v 1.1.1.1 2009/03/30 19:21:23 mstapelberg Exp $

CATEGORIES=net
DISTNAME=vnstat-1.6
HOMEPAGE=http://humdi.net/vnstat/
COMMENT=Small network traffic monitor
MASTER_SITES=http://humdi.net/vnstat/
DISTFILES=${DISTNAME}_bsd.tar.gz

USE_TOOLS+=gmake
BUILD_TARGET=vnstat
PKG_DESTDIR_SUPPORT=user-destdir

VNSTAT_CONFIG=	${PKG_SYSCONFDIR}/vnstat.conf
VNSTAT_EGDIR=	${PREFIX}/share/examples

SUBST_CLASSES+=			fix-dbpath
SUBST_STAGE.fix-dbpath=		pre-configure
SUBST_MESSAGE.fix-dbpath=	Fixing path to database files
SUBST_FILES.fix-dbpath=		src/vnstat.h cfg/vnstat.conf
SUBST_SED.fix-dbpath=		-e 's,/var/db/,${PREFIX}/var/,g'
SUBST_SED.fix-dbpath+=		-e 's,/var/lib/,${PREFIX}/var/,g'

CONF_FILES= ${VNSTAT_EGDIR}/vnstat.conf ${VNSTAT_CONFIG}

INSTALLATION_DIRS+=		var/vnstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstat ${DESTDIR}${PREFIX}/bin/vnstat
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf ${DESTDIR}${VNSTAT_EGDIR}/vnstat.conf
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR:Q}/man1/vnstat.1

.include "../../mk/bsd.pkg.mk"
