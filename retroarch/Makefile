# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	retroarch-0.9.7
CATEGORIES=	emulators
MASTER_SITES=	http://themaister.net/retroarch-dl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://themaister.net/retroarch.html
COMMENT=	Multi-system emulator for Linux, Windows, Mac OS X and *BSD
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=			c c++
USE_TOOLS+=			gmake pkg-config
HAS_CONFIGURE=			yes
CONFIGURE_ARGS+=		--prefix=${PREFIX}
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.10

SUBST_CLASSES+=			pkgmandir
SUBST_STAGE.pkgmandir=		pre-install
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_FILES.pkgmandir=		Makefile
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|g"

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
