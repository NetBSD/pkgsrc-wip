# $NetBSD$

GITHUB_PROJECT=	code
GITHUB_TAG=	3.4.1
DISTNAME=	3.4.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=elementary/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elementary/code/
COMMENT=	Elementory code editor
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/code-3.4.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wip/granite/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
