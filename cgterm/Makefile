# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cgterm-1.7b2
CATEGORIES=	wip
MASTER_SITES=	http://www.paradroid.net/cgterm/

MAINTAINER=	rodo@zlug.org
HOMEPAGE=	http://www.paradroid.net/cgterm/
COMMENT=	Commodore Graphics Telnet Client
#LICENSE=	# TODO: (see mk/license.mk)

LICENSE=                2-clause-bsd

NO_CONFIGURE=   yes

USE_TOOLS+=     gmake

SUBST_CLASSES+= 		fix-paths
SUBST_STAGE.fix-paths= 		post-patch
SUBST_MESSAGE.fix-paths= 	Fixing absolute paths.
SUBST_FILES.fix-paths= 		Makefile
SUBST_SED.fix-paths= 		-e 's,/usr/local,${PREFIX},g'

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
