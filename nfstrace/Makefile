# $NetBSD$

DISTNAME=		nfstrace-0.4.3.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=epam/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://epam.github.io/nfstrace/
COMMENT=		Network file system monitor and analyzer
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++

# Gmock for tests

.include "../../devel/cmake/build.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
