# $NetBSD$

GITHUB_PROJECT=	samurai
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	0.7
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/samurai/
COMMENT=	Ninja-compatible build tool written in C
LICENSE=	isc

WRKSRC=	${WRKDIR}/samurai-0.7

BUILD_TARGET=	samu

# \todo: https://github.com/michaelforney/samurai/pull/28
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's,PREFIX=,PREFIX?=,g'
SUBST_SED.prefix+=	-e 's,(PREFIX)/share/man,(PREFIX)/man,g'

.include "../../mk/bsd.pkg.mk"
