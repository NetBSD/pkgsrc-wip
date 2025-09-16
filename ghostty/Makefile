# $NetBSD$

DISTNAME=		ghostty-1.2.0
CATEGORIES=		x11
MASTER_SITES=		https://release.files.ghostty.org/${PKGVERSION_NOREV}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ghostty.org/
COMMENT=		Fast, feature-rich cross-platform terminal emulator
LICENSE=		mit

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

ZIGBUILDMODE=		--release=fast
ZIGBUILDARGS+=		-Dman-dir=${PKGMANDIR}

# Temporarily required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=	yes

.include "zig-depends.mk"

.include "../../lang/zig/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
# XXX gtk4-layer-shell
.include "../../mk/bsd.pkg.mk"
