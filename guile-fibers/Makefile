# $NetBSD$

GITHUB_PROJECT=	fibers
DISTNAME=	fibers-1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wingo/}
GITHUB_RELEASE=	v1.1.1

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/wingo/fibers/
COMMENT=	Go-like concurrency for Guile in the tradition of Concurrent ML
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
