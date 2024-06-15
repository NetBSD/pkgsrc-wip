# $NetBSD$

DISTNAME=	Tuba-0.7.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=GeopJr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GeopJr/Tuba/
COMMENT=	Mastodon browser
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.5
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
