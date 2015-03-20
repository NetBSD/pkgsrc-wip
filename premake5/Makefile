# $NetBSD: Makefile,v 1.1 2015/03/20 16:56:17 nros Exp $

PREMAKE5_VERSION=	5.0
DISTNAME=		premake-${PREMAKE5_VERSION}-alpha1-src
PKGNAME=		premake5-${PREMAKE5_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://premake.bitbucket.org/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/premake-${PREMAKE5_VERSION}-alpha1

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILD_DIRS+=		build/gmake.unix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
