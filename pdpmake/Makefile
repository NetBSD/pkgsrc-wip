# $NetBSD$

DISTNAME=		pdpmake-2.0.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=rmyorston/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/rmyorston/pdpmake/
COMMENT=		Public domain POSIX make
LICENSE=		public-domain

CFLAGS.Darwin=		-D_DARWIN_C_SOURCE -Dst_mtim=st_mtimespec

BUILD_TARGET=		make
TEST_TARGET=		test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make ${DESTDIR}${PREFIX}/bin/pdpmake
	${INSTALL_MAN} ${WRKSRC}/pdpmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
