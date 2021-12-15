# $NetBSD$

PREMAKE5_VERSION=	5.0.0
DISTNAME=		premake-${PREMAKE5_VERSION}-beta1-src
PKGNAME=		premake5-${PREMAKE5_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=premake/}
GITHUB_PROJECT=		premake-core
GITHUB_RELEASE=		v${PREMAKE5_VERSION}-beta1
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://premake.github.io/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/premake-${PREMAKE5_VERSION}-beta1-src

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILD_DIRS+=		build/gmake2.unix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
