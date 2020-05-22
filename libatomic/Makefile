# $NetBSD: Makefile,v 1.2 2020/05/17 19:47:19 rillig Exp $

GCC_PKGNAME=		libatomic
.include		"version.mk"

DISTNAME=	gcc-${GCC10_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-${GCC10_DIST_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC10_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	Atomic fallback implementation for GCC
LICENSE=	gnu-gpl-v3

.if empty(PKGSRC_COMPILER:Mgcc*)
PKG_SKIP_REASON+=	"Uses esoteric GCC-specific features"
.endif

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE_STRICT=	no
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/libatomic/configure

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
