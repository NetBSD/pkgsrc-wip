# $NetBSD$

VERSION=	1.3.1
GITHUB_PROJECT=	fibers
DISTNAME=	fibers-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wingo/}
GITHUB_RELEASE=	v${VERSION}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/wingo/fibers/
COMMENT=	Go-like concurrency for Guile in the tradition of Concurrent ML
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.1.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
