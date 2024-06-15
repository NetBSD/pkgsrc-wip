# $NetBSD$

DISTNAME=	obfuscate-0.0.10
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.gnome.org/World/obfuscate/uploads/7286537df58cb49424c1b4871b915421/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/World/obfuscate/
COMMENT=	Censor private information
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
