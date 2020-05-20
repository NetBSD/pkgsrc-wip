# $NetBSD: Makefile,v 1.2 2020/05/17 19:47:19 rillig Exp $

GCC_PKGNAME=		gcc10
.include		"version.mk"

DISTNAME=	gcc-${GCC10_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-${GCC10_DIST_VERSION}
PKGREVISION=	1
## When bumping the PKGREVISION of this package the PKGREVISION of
## lang/gcc10-libs needs to be bump to be at least 1 more than the
## PKGREVISION of this package!
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC10_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) - 10.0 Release Series
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

NOT_FOR_PLATFORM=	Interix-*-*

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake makeinfo sed:run tar:build

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/libatomic/configure
INFO_FILES=		yes

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

LANGS=			c

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
