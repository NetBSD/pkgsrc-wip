# $NetBSD: Makefile,v 1.1 2014/01/04 16:23:02 nros Exp $
#

PREMAKE4_VERSION=	4.3
DISTNAME=		premake-${PREMAKE4_VERSION}-src
PKGNAME=		premake4-${PREMAKE4_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://industriousone.com/premake/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/premake-${PREMAKE4_VERSION}

do-build:
	cd ${WRKSRC}/build/gmake.unix/ && ${MAKE_PROGRAM}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake4 ${DESTDIR}${PREFIX}/bin/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
