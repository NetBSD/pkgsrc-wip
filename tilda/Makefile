# $NetBSD: Makefile,v 1.5 2009/06/11 08:10:32 thomasklausner Exp $
#

DISTNAME=		tilda-0.09.2
PKGREVISION=		2
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tilda/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://tilda.sourceforge.net/
COMMENT=		Terminal like the classic first-person-shooter games.

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../devel/confuse/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
