# $NetBSD: Makefile,v 1.3 2004/05/02 21:53:01 blef Exp $
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
USE_BUILDLINK3=		yes
WRKSRC=			${WRKDIR}/Premake-1.2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/premake ${PREFIX}/bin/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
