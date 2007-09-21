# $NetBSD: Makefile,v 1.3 2007/09/21 13:06:56 thomasklausner Exp $
#

DISTNAME=		tilda-0.09.2
PKGREVISION=		1
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tilda/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://tilda.sourceforge.net/
COMMENT=		Terminal like the classic first-person-shooter games.

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../wip/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
