# $NetBSD$

DISTNAME=	i3lockr-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=owenthewizard/}
GITHUB_TAG=	b4acd8a87957806681dc57876af01c6d435bd8e3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/owenthewizard/i3lockr/
COMMENT=	Distort a screenshot and run i3lock
LICENSE=	mit OR apache-2.0

# The xcb crate depends on any version of python 3.
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
SCRAP_REV=	21b9f233bb8ad0b650b8eabb8a796054538c64be
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	scrap-${SCRAP_REV}.tar.gz
SITES.scrap-${SCRAP_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=owenthewizard/}scrap/archive/${SCRAP_REV}.tar.gz

post-extract:
	mv ${WRKDIR}/scrap-* ${WRKSRC}

#DEPENDS+=	i3lock-[0-9]*:../../x11/i3lock

.include "../../mk/bsd.prefs.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
