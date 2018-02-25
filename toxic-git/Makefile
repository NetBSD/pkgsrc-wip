# $NetBSD$

DISTNAME=	toxic-0.8.0
CATEGORIES=	chat
GIT_REPO=	https://github.com/JFreegman/toxic.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.tox.chat/clients/toxic
COMMENT=	CLI Tox client
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c

.include "options.mk"

.include "../../wip/toxcore-git/buildlink3.mk"

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
