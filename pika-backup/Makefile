# $NetBSD$

DISTNAME=	pika-backup-v0.3.2
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://gitlab.gnome.org/World/pika-backup/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/World/pika-backup/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

REPLACE_PYTHON+=	build-aux/*.py

USE_LANGUAGES+=	c c++

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif
TOOL_DEPENDS+=	gettext-tools>=0.19.4nb1:../../devel/gettext-tools

USE_TOOLS+=	mgsfmt pkg-config

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
