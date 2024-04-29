# $NetBSD$

DISTNAME=	wadptr-3.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=fragglet/}
GITHUB_TAG=	${DISTNAME}
GITHUB_PROJECT=	wadptr
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://soulsphere.org/projects/wadptr/
COMMENT=	Command-line tool for compressing Doom WAD files
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c99
MAKE_FLAGS+=	PREFIX=${PREFIX}
USE_TOOLS+=	gmake

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man path
SUBST_FILES.man=	Makefile
SUBST_SED.man+=	-e 's,share/man,${PKGMANDIR},g'

PLIST.bsd=		yes

.include "../../mk/bsd.pkg.mk"
