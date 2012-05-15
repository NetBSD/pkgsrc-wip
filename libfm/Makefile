# $NetBSD: Makefile,v 1.1.1.1 2012/05/15 03:20:47 jeremy-c-reed Exp $
#

DISTNAME=	libfm-0.1.17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS=		intltool pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/menu-cache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
