# $NetBSD: Makefile,v 1.50 2024/11/14 22:19:36 wiz Exp $

DISTNAME=	radare2-5.9.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radareorg/}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	vector35-arch-arm64-55d73c6bbb94448a5c615933179e73ac618cf876.tar.gz
DISTFILES+=	vector35-arch-armv7-f270a6cc99644cb8e76055b6fa632b25abd26024.tar.gz
SITES.vector35-arch-arm64-55d73c6bbb94448a5c615933179e73ac618cf876.tar.gz= \
		-${MASTER_SITES:=vector35-arch-arm64/archive/55d73c6bbb94448a5c615933179e73ac618cf876.tar.gz}
SITES.vector35-arch-armv7-f270a6cc99644cb8e76055b6fa632b25abd26024.tar.gz= \
		-${MASTER_SITES:=vector35-arch-armv7/archive/f270a6cc99644cb8e76055b6fa632b25abd26024.tar.gz}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.radare.org/
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-sysmagic
CONFIGURE_ARGS+=	--with-syscapstone
CONFIGURE_ARGS+=	--with-syszip
PKGCONFIG_OVERRIDE+=	pkgcfg/*.pc*
USE_TOOLS+=		gmake patch pkg-config perl

REPLACE_SH+=		scripts/licenses.r2.js

# node
CHECK_INTERPRETER_SKIP+=	share/radare2/${PKGVERSION_NOREV}/www/m/fonts/iconjar-map.js

#R2VERSION=	${PKGVERSION_NOREV}-git # trunk revision
R2VERSION=	${PKGVERSION_NOREV} # release version
R2VERSION_MN=	${R2VERSION:C/([0-9]*\.[0-9]*).*/\1/}

PLIST_SUBST+=	R2VERSION=${R2VERSION}
PLIST_SUBST+=	R2VERSION_MN=${R2VERSION_MN}

PRINT_PLIST_AWK+=	{ gsub(/${R2VERSION}/, "$${R2VERSION}") }
PRINT_PLIST_AWK+=	{ gsub(/${R2VERSION_MN}/, "$${R2VERSION_MN}") }

post-extract:
	${MV} ${WRKDIR}/vector35-arch-arm64-55d73c6bbb94448a5c615933179e73ac618cf876\
		${WRKSRC}/libr/arch/p/arm/v35/arch-arm64
	${MV} ${WRKDIR}/vector35-arch-armv7-f270a6cc99644cb8e76055b6fa632b25abd26024 \
		${WRKSRC}/libr/arch/p/arm/v35/arch-armv7

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
