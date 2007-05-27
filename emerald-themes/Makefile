# $NetBSD: Makefile,v 1.1 2007/05/27 06:53:43 bsadewitz Exp $
#

DISTNAME=	emerald-themes-0.2.1
CATEGORIES=	wm

COMMENT=	Emerald themes for beryl.

.include "../../wip/beryl/Makefile.inc"

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash gtar

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_BASH=	themes/import.sh

SUBST_CLASSES+=	gtar
SUBST_SED.gtar+= -e "s,tar,${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tar,g"
SUBST_MESSAGE.gtar+= replacing tar
SUBST_FILES.gtar+= themes/import.sh
SUBST_STAGE.gtar+=post-configure


.include "../../mk/bsd.pkg.mk"
