# $NetBSD: Makefile,v 1.1.1.1 2006/03/12 22:16:08 poppnk Exp $
#

DISTNAME=		tilda-0.09.2
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tilda/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://kent.dl.sourceforge.net/sourceforge/tilda/
COMMENT=		Terminal like the classic first-person-shooter games.

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../wip/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
