# $NetBSD: Makefile,v 1.2 2004/01/25 02:33:18 grantbeattie Exp $
#

DISTNAME=		premake-src-1.2
PKGNAME=		premake-1.2
WRKSRC=			${WRKDIR}/Premake-1.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build script generator

USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/premake ${PREFIX}/bin/

.include "../../lang/lua/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
