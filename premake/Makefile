# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:29 othyro Exp $
#

DISTNAME=		premake-src-3.1
PKGNAME=		premake-3.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://premake.sourceforge.net/
COMMENT=		Build script generator

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/Premake-3.1

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${DESTDIR}${PREFIX}/bin/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
