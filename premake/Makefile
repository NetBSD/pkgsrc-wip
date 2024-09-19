# $NetBSD: Makefile,v 1.10 2014/01/04 13:38:12 nros Exp $
#

DISTNAME=		premake-src-3.7
PKGNAME=		premake-3.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://premake.sourceforge.net/
COMMENT=		Build script generator
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/Premake-3.7

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${DESTDIR}${PREFIX}/bin/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
