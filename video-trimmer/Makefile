# $NetBSD$

DISTNAME=	video-trimmer-v0.7.1
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://gitlab.gnome.org/YaLTeR/video-trimmer/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://apps.gnome.org/app/org.gnome.gitlab.YaLTeR.VideoTrimmer/
COMMENT=	Trim videos quickly
#LICENSE=	# TODO: (see mk/license.mk)

TOOL_DEPENDS+=	blueprint-compiler-[0-9]*:../../wip/blueprint-compiler

USE_LANGUAGES=		c
USE_TOOLS+=		msgfmt pkg-config

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- xml
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif
TOOL_DEPENDS+=	gettext-tools>=0.19.4nb1:../../devel/gettext-tools

.include "cargo-depends.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
