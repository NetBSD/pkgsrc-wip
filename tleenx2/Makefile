# $NetBSD: Makefile,v 1.1.1.1 2003/11/29 21:07:41 mpasternak Exp $
#

DISTNAME=		TleenX2-20031002
PKGNAME=		tleenx2-20031002
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tleenx/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://tleenx.sourceforge.net/
COMMENT=		Client to tlen.pl - polish IM / chat system

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../wip/libtlen/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
