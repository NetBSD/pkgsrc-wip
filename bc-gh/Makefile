# $NetBSD$

DISTNAME=       bc-2.0.0
PKGNAME=        bc-gh-2.0.0
CATEGORIES=     math
MASTER_SITES=   ${MASTER_SITE_GITHUB:=gavinhoward/}
GITHUB_PROJECT= bc
GITHUB_RELEASE= 2.0.0
EXTRACT_SUFX=   .tar.xz

MAINTAINER=     yzena.tech@gmail.com
HOMEPAGE=       https://github.com/gavinhoward/bc
COMMENT=        Implementation of POSIX bc with GNU extensions
LICENSE=        2-clause-bsd

HAS_CONFIGURE=          yes
CONFIGURE_SCRIPT=       configure.sh
CONFIGURE_ARGS=         -G
CONFIGURE_ENV=          EXECSUFFIX="-gh" MANDIR="${PREFIX}/man" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
