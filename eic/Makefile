# $NetBSD: Makefile,v 1.9 2012/09/28 22:07:31 asau Exp $
#

DISTNAME=		EiCsrc_4.3.0
PKGNAME=		EiC-4.3.0
WRKSRC=			${WRKDIR}/EiC/
CATEGORIES=		lang
MASTER_SITES=		http://rpm.rutgers.edu/repository/solaris/SOURCES/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		C style scripting lang


USE_TOOLS+=		gmake

do-configure:
		cd ${WRKSRC} && config/makeconfig

do-build:	do-install

do-install:
		cd ${WRKSRC} && ${GMAKE} INSTALL_DIR=${PREFIX}/bin;	\
		${INSTALL_DATA_DIR} ${PREFIX}/EiC; cd ${WRKSRC}; ${CP} -r doc include lib main \
		module test BugList.html Change.html Distribution.html LICENCE Maintenance \
		${PREFIX}/EiC; ${CP} ${WRKSRC}/eic.man ${PREFIX}/${PKGMANDIR}/man1/eic.man.1

.include "../../mk/bsd.pkg.mk"
