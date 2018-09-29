# $NetBSD: Makefile,v 1.27 2018/08/16 18:55:09 adam Exp $
#

DISTNAME=	zathura-pdf-mupdf-0.3.3
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura/plugins/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-pdf-mupdf/
COMMENT=	Add PDF support to zathura using mupdf rendering engine
LICENSE=	zlib

GIT_REPOSITORIES=		zathura-pdf-mupdf
GIT_BRANCH.zathura-pdf-mupdf=	develop
GIT_REPO.zathura-pdf-mupdf=	https://git.pwmt.org/pwmt/zathura-pdf-mupdf.git
WRKSRC=				${WRKDIR}/zathura-pdf-mupdf

USE_TOOLS+=	pkg-config

# Link to external dependencies (jpeg, jbig2dec, openjpeg)
MESON_ARGS+=	-D link-external=true

CPPFLAGS+=	-D_XOPEN_SOURCE=600

.include "../../devel/py-meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/mupdf/buildlink3.mk"
.include "../../wip/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
