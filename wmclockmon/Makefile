# $NetBSD: Makefile,v 1.2 2004/04/25 06:43:29 blef Exp $
#

DISTNAME=	wmclockmon-0.2.2
CATEGORIES=	x11 sysutils
MASTER_SITES=   http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://tnemeth.free.fr/projets/dockapps.html
COMMENT=	Windowmaker dockapp for time/date

USE_BUILDLINK3= yes
USE_X11=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmclockmon
	${INSTALL_DATA} ${WRKSRC}/doc/sample.wmclockmonrc ${PREFIX}/share/examples/wmclockmon

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
