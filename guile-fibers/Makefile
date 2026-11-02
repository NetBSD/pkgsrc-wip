# $NetBSD$

VERSION=		2.0.0
DISTNAME=		fibers-${VERSION}
PKGNAME=		guile-fibers-${VERSION}
MASTER_SITES=		${MASTER_SITE_CODEBERG:=guile/}
CODEBERG_PROJECT=	fibers
CODEBERG_TAG=		v${VERSION}
CATEGORIES=		devel

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://codeberg.org/guile/fibers
COMMENT=	Go-like concurrency for Guile in the tradition of Concurrent ML
LICENSE=	gnu-lgpl-v3

# Upstream seems to think it's better not to provide a "make dist" artifact.
# Instead, the "release" is a git snapshot.
USE_TOOLS+=	pkg-config autoconf automake makeinfo
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# Unpacks to "fibers" with no version.
WRKSRC=		${WRKDIR}/fibers

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

#TEST_ENV+=	FIBERS_EXPENSIVE_TESTS=t
TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.1.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
