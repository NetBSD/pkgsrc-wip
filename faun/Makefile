# $NetBSD$

DISTNAME=	v0.2.1
PKGNAME=	faun-${DISTNAME:S,^v,,}
CATEGORIES=	audio
MASTER_SITES=	https://codeberg.org/wickedsmoke/faun/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wickedsmoke.codeberg.page/faun_doc/
COMMENT=	High-level C audio library
LICENSE=	mit

WRKSRC=		${WRKDIR}/faun
HAS_CONFIGURE=	yes
USE_TOOLS+=	bash:run gmake

REPLACE_BASH=	configure

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
