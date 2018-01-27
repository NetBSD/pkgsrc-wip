# $NetBSD$

DISTNAME=	toxcore-0.2.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=toktok/}

GIT_REPOSITORIES=	c-toxcore
GIT_REPO.c-toxcore=	http://github.com/toktok/c-toxcore.git
WRKSRC=			${WRKDIR}/c-toxcore

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
