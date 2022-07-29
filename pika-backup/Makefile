# $NetBSD$

DISTNAME=	pika-backup-v0.4.2
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.gnome.org/World/pika-backup/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/World/pika-backup/
COMMENT=	GNOME Backup application based on borg-backup
LICENSE=	gnu-gpl-v3

REPLACE_PYTHON+=	build-aux/*.py

USE_LANGUAGES+=	c c++

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif
TOOL_DEPENDS+=	gettext-tools>=0.19.4nb1:../../devel/gettext-tools

USE_TOOLS+=	itstool msgfmt pkg-config

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.1
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.6
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
