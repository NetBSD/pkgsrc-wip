# $NetBSD$

PKGNAME=		zero-epwing-0.1
CATEGORIES=		textproc

GIT_REPOSITORIES=	zero-epwing
GIT_REPO.zero-epwing=	git://github.com/FooSoft/zero-epwing.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FooSoft/zero-epwing
COMMENT=	Tool that converts EPWING files to JSON
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake perl # required for the bundled libeb

WRKSRC=		${WRKDIR}/zero-epwing

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
	set -e ; cd ${WRKSRC}/eb; \
	./configure --disable-shared --disable-ebnet --disable-nls

	set -e ; cd ${WRKSRC}; \
	${PKGSRC_SETENV} ${_CONFIGURE_CMAKE_ENV} \
		cmake ${CMAKE_ARGS} ${CMAKE_ARG_PATH}

do-build:
	set -e ; cd ${WRKSRC}/eb \
	&& ${MAKE_PROGRAM}

	set -e ; cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
		${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} \
		${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zero-epwing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../textproc/jansson/buildlink3.mk"
#include "../../wip/libeb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
