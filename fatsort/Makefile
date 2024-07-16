# $NetBSD$

DISTNAME=	fatsort-1.6.5.640
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fatsort/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://fatsort.sourceforge.io/
COMMENT=	FAT sorting tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

# tests require en_US.UTF-8 and en_US.iso88591 locales to be available
TEST_TARGET=	tests
TEST_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	SBINDIR=${PREFIX}/sbin

# Makefile installs the man page as 755
post-install:
	chmod 644 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fatsort.1

.include "../../mk/bsd.pkg.mk"
