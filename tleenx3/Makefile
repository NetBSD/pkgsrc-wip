# $NetBSD: Makefile,v 1.7 2010/06/13 22:47:20 thomasklausner Exp $
#

DISTNAME=		TleenX3-0.1
PKGNAME=		${DISTNAME:S/T/t/:S/X/x/}
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tleenx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tleenx.sourceforge.net/
COMMENT=		Polish IM communication client

GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../wip/libtlen2/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
