# $NetBSD: Makefile,v 1.5 2005/05/24 10:29:38 rillig Exp $
#

DISTNAME=		EiCsrc_4.3.0
PKGNAME=		EiC-4.3.0
WRKSRC=			${WRKDIR}/EiC/
CATEGORIES=		lang
MASTER_SITES=		http://eic.sourceforge.net/download/eicdist/4_3_0/
EXTRACT_SUFX=		.tgz

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://eic.sourceforge.net/download/eicdist/4_3_0/
COMMENT=		C style scripting lang

USE_TOOLS+=		gmake

do-configure:
		cd ${WRKSRC} && config/makeconfig

do-build:	do-install

do-install:
		cd ${WRKSRC} && ${GMAKE} INSTALL_DIR=${PREFIX}/bin;	\
		${INSTALL_DATA_DIR} ${PREFIX}/EiC; cd ${WRKSRC}; ${CP} -r doc include lib main \
		module test BugList.html Change.html Distribution.html LICENCE Maintenance \
		${PREFIX}/EiC; ${CP} ${WRKSRC}/eic.man ${PREFIX}/man/man1/eic.man.1

.include "../../mk/bsd.pkg.mk"
