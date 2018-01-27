# $NetBSD: Makefile,v 1.2 2012/10/07 16:22:56 asau Exp $
#

DISTNAME=	seturgent-1.4
CATEGORIES=	x11
MASTER_SITES=	http://www.codemadness.nl/downloads/projects/seturgent/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://www.codemadness.nl/downloads/projects/seturgent/
COMMENT=	Set an application urgency hint using x11
LICENSE=	mit

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
