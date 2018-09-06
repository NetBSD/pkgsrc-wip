# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	hplibunwind-1.1.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	libunwind
GIT_REPO.libunwind=	http://git.savannah.gnu.org/r/libunwind.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/libunwind/
COMMENT=	NONGNU libunwind
LICENSE=	mit

WRKSRC=			${WRKDIR}/libunwind

GNU_CONFIGURE=	yes

USE_TOOLS+=	autoreconf autoconf automake

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-coredump
CONFIGURE_ARGS+=	--enable-tests

pre-configure:
	${RUN} cd ${WRKSRC} && pwd && ./autogen.sh

.include "../../wip/mk/git-package.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
