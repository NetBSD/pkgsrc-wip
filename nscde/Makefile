# $NetBSD$

DISTNAME=	nscde-2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NsCDE/}
GITHUB_PROJECT=	NsCDE

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/NsCDE/NsCDE
COMMENT=	Not so Common Desktop Environment
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gsed

DEPENDS+=	fvwm3-[0-9]*:../../wm/fvwm3
#DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

# XXX Not entirely sure which Pythons are necessary and sufficient
#DEPENDS+=	python3.8-[0-9]*:../../lang/python38

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
