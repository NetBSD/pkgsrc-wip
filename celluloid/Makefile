# $NetBSD$

DISTNAME=	celluloid-0.18
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=celluloid-player/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://celluloid-player.github.io
COMMENT=	Simple GTK+ frontend for mpv
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
