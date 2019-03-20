# $NetBSD$

GITHUB_PROJECT=	termbox
GITHUB_TAG=	v1.1.2
DISTNAME=	${GITHUB_TAG}
PKGNAME=	termbox-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nsf/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://github.com/nsf/termbox/
COMMENT=	Library for writing text-based user interfaces
LICENSE=	mit

PYTHON_FOR_BUILD_ONLY=	yes

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEPENDS+= waf>=1.8.4:../../devel/waf

WAF_ENV=	CC=${CC:Q} PREFIX=${PREFIX:Q} \
		CFLAGS=${CFLAGS:Q} \
		LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR:Q}

.include "../../devel/waf/waf.mk"
.include "../../mk/bsd.pkg.mk"
