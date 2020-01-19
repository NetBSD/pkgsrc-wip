# $NetBSD: Makefile,v 1.3 2015/03/20 17:56:08 nros Exp $

PREMAKE4_VERSION=	4.3
DISTNAME=		premake-${PREMAKE4_VERSION}-src
PKGNAME=		premake4-${PREMAKE4_VERSION}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=premake/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://premake.github.io/
COMMENT=		Build script generator
LICENSE=		modified-bsd AND mit

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/premake-${PREMAKE4_VERSION}

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILD_DIRS+=		build/gmake.unix

INSTALLATION_DIRS=	bin share/doc/premake4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake4 \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
		${DESTDIR}${PREFIX}/share/doc/premake4/license.premake4
	${INSTALL_DATA} ${WRKSRC}/src/host/lua-5.1.4/COPYRIGHT \
		${DESTDIR}${PREFIX}/share/doc/premake4/license.lua

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
