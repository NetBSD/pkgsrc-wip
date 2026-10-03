# $NetBSD$

# https://codeberg.org/guile/fibers/archive/v1.4.3.tar.gz
VERSION=		1.4.3
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
USE_TOOLS+=	pkg-config autoconf automake libtool makeinfo
GNU_CONFIGURE=	yes

# Unpacks to "fibers" with no version.
WRKSRC=		${WRKDIR}/fibers

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# Define ? to run "espensive" tests.
TEST_TARGET=	check

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.1.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
