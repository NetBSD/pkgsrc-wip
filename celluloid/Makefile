# $NetBSD$

DISTNAME=	celluloid-0.19
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=celluloid-player/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://celluloid-player.github.io/
COMMENT=	Simple GTK+ frontend for mpv
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

# Requires --desktop in msgfmt.
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../multimedia/mpv/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
