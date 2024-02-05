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

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake flex bison	# won't work with other
USE_TOOLS+=	perl bash:run
# for patched configure.ac, remove when upstreamed
USE_TOOLS+=	aclocal autoheader autoconf automake
USE_LANGUAGES=	c c++

REPLACE_PERL+=	doc/vim2html.pl
REPLACE_BASH+=	src/fimgs

TEST_TARGET=	tests

# for patched configure.ac, remove when upstreamed
pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"	# needs GNU
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libcaca/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
