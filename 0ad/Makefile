# $NetBSD$

.include "Makefile.common"

DISTNAME=	${DISTVERSION}-build
PKGNAME=	${DISTNAME:S/-unix-build//:S/-alpha/.alpha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Historical real-time strategy game
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-build//}
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake perl bash

DEPENDS+=	0ad-data-${PKGVERSION}:../../wip/0ad-data

do-configure:
	${RUN} cd ${WRKSRC} && ./build/workspaces/clean-workspaces.sh
	${RUN} cd ${WRKSRC} && ./build/workspaces/update-workspaces.sh \
		--bindir=${PREFIX}/bin \
		--datadir=${PREFIX}/share/${PKGBASE} \
		--libdir=${PREFIX}/lib/${PKGBASE} \
		--with-system-nvtt \
		--with-system-mozjs31

do-build:
	${RUN} cd ${WRKSRC} && \
		${GMAKE} config=release verbose=1 -C build/workspaces/gcc

.include "../../chat/gloox/buildlink3.mk"
.include "../../wip/miniupnpc/buildlink3.mk"
.include "../../wip/enet/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/spidermonkey31/buildlink3.mk"
.include "../../graphics/nvidia-texture-tools/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
