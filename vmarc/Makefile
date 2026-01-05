# $NetBSD$

DISTNAME=	vma-22.204a
CATEGORIES=	devel
MASTER_SITES=	https://www.homerow.net/files/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.homerow.net/files/
COMMENT=	Create/extract VM ARC files
LICENSE=	public-domain

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_DIRS+=	bin

# Use for cli-only build, not depending on wxGTK32.
#BUILD_TARGET=	cli

do-install:
	cd ${WRKSRC} && \
		mkdir ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} src/vma ${DESTDIR}${PREFIX}/bin/ && \
		${INSTALL_PROGRAM} src/vmagui ${DESTDIR}${PREFIX}/bin/

.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
