# $NetBSD$

DISTNAME=	jobd
GITHUB_TAG=	v${VERSION}
VERSION=	0.7.1
PKGNAME=	jobd-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mheily/}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Job management framework
HOMEPAGE=	https://github.com/mheily/jobd/
LICENSE=	isc

USE_LANGUAGES+=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../wip/libucl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
