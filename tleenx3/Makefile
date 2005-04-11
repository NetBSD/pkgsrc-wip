# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:03 tvierling Exp $
#

DISTNAME=		TleenX3-0.1
PKGNAME=		${DISTNAME:S/T/t/:S/X/x/}
CATEGORIES=	        chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tleenx/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://tleenx.sourceforge.net/
COMMENT=		Polish IM communication client

GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../wip/libtlen2/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
