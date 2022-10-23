# $NetBSD$

DISTNAME=	sqlux-1.0.5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SinclairQL/}
GITHUB_PROJECT=	sQLux
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/SinclairQL/sQLux
COMMENT=	Sinclair QL emulator
# XXX this code's license is actually extremely unclear -- they're moving
# "towards GPL style licensing as far as possible," whatever the heck that
# means.
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
