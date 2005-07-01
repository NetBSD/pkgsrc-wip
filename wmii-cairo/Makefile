# $NetBSD: Makefile,v 1.5 2005/07/01 13:11:11 leonardschmidt Exp $
#

.include "../../wip/wmii/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-cairo-/}

COMMENT+=	(built with cairo support)

CONFLICTS=	wmii-[0-9]*

MAKE_ENV+=	DRAW=cairo

SUBST_CLASSES+=	conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	config.mk
SUBST_SED.conf=	-e 's,^\#CAIRO,CAIRO,'

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
