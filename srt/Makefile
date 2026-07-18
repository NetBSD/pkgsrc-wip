# $NetBSD$

DISTNAME=	srt-1.5.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Haivision/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/Haivision/srt/
COMMENT=	Secure Reliable Transport (SRT) Protocol
LICENSE=	mpl-2.0

.include "../../devel/cmake/build.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}

HAS_CONFIGURE=	yes
USE_TOOLS+=	bash:run pkg-config
USE_LANGUAGES=	c c++

REPLACE_BASH+=	scripts/srt-ffplay

PKGCONFIG_OVERRIDE+=	scripts/srt.pc.in

# pthread_setname_np
CXXFLAGS.NetBSD+=	-fpermissive

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
