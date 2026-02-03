# $NetBSD$

DISTNAME=	basu-0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~emersion/basu/archive/
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~emersion/basu/
COMMENT=	The sd-bus library, extracted from systemd
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
WRKSRC=		${WRKDIR}/basu-v${PKGVERSION_NOREV}
REPLACE_PYTHON=	src/basic/generate-gperfs.py
MESON_ARGS+=	-Daudit=disabled
MESON_ARGS+=	-Dlibcap=disabled

#CFLAGS+=		-O0 -g
#INSTALL_UNSTRIPPED=	yes

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
