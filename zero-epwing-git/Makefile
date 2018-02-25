# $NetBSD$

PKGNAME=	zero-epwing-0.1
CATEGORIES=	textproc
GIT_REPO=	git://github.com/FooSoft/zero-epwing.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FooSoft/zero-epwing
COMMENT=	Tool that converts EPWING files to JSON
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake perl # required for the bundled libeb

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

CFLAGS+=	-std=gnu99


# Okay, here's the rationale for the following mess:
#
# zero-epwing requires libeb, *however*, it only works with
# the author's fork, which is included with the source code.
# So, we have to build that fork of libeb here as well, and then
# statically link it.
#
# ...unless everyone wants a libeb-but-only-for-zero-epwing pkg in pkgsrc.

do-configure:
	${RUN} cd ${WRKSRC}/eb; \
	./configure --disable-shared --disable-ebnet --disable-nls

	${RUN} cd ${WRKSRC}; \
	${PKGSRC_SETENV} ${_CONFIGURE_CMAKE_ENV} \
		cmake ${CMAKE_ARGS} ${CMAKE_ARG_PATH}

pre-build:
	${RUN} cd ${WRKSRC}/eb && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zero-epwing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../textproc/jansson/buildlink3.mk"
#include "../../wip/libeb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
