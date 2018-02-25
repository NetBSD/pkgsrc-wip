# $NetBSD$

DISTNAME=	toxcore-0.2.0
CATEGORIES=	chat
GIT_REPO=	https://github.com/toktok/c-toxcore.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.chat/
COMMENT=	Tox protocol library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c

#SUBST_FILES.autotools=	autogen.sh

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../audio/libopus/buildlink3.mk"
#.include "../../devel/check/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
