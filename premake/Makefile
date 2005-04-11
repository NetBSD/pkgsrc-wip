# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:50 tvierling Exp $
#

DISTNAME=		premake-src-1.2
PKGNAME=		premake-1.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build script generator

USE_GNU_TOOLS+=		make
WRKSRC=			${WRKDIR}/Premake-1.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/premake ${PREFIX}/bin/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
