# $NetBSD: Makefile,v 1.1.1.1 2003/07/22 16:51:29 poppnk Exp $
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

USE_GMAKE=		yes
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/premake ${PREFIX}/bin/

.include "../../lang/lua/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
