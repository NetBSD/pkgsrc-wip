# $NetBSD$

DISTNAME=	fim-0.6-rc2
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	graphics
MASTER_SITES=	http://download.savannah.nongnu.org/releases/fbi-improved/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/fbi-improved/
COMMENT=	Lightweight universal image viewer
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake flex bison perl bash:run
# for patched configure.ac, remove when upstreamed
USE_TOOLS+=		aclocal autoheader autoconf automake
USE_LANGUAGES=		c c++
#USE_CXX_FEATURES+=	c++11	# starting with fim-0.7

REPLACE_PERL+=		doc/vim2html.pl
REPLACE_BASH+=		src/fimgs

TEST_TARGET=		tests

# for patched configure.ac, remove when upstreamed
pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "options.mk"

.include "../../devel/readline/buildlink3.mk"	# needs GNU
.include "../../mk/bsd.pkg.mk"
