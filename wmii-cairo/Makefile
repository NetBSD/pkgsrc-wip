# $NetBSD: Makefile,v 1.6 2005/08/27 10:45:12 leonardschmidt Exp $
#

.include "../../wip/wmii/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-cairo-/}

COMMENT+=	(built with cairo support)

CONFLICTS=	wmii-[0-9]*

MAKE_ENV+=	DRAW=cairo

BROKEN=		Current version lacks cairo support

SUBST_CLASSES+=	conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	config.mk
SUBST_SED.conf=	-e 's,^\#CAIRO,CAIRO,'

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
