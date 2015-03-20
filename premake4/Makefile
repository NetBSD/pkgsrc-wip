# $NetBSD: Makefile,v 1.3 2015/03/20 17:56:08 nros Exp $

PREMAKE4_VERSION=	4.3
DISTNAME=		premake-${PREMAKE4_VERSION}-src
PKGNAME=		premake4-${PREMAKE4_VERSION}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://premake.bitbucket.org/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/premake-${PREMAKE4_VERSION}

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILD_DIRS+=		build/gmake.unix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake4 ${DESTDIR}${PREFIX}/bin/

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
