# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:39 grantbeattie Exp $
#

DISTNAME=		liferea-0.3.3
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Liferea is a simple FeedReader clone for reading RSS/RDF feeds

USE_BUILDLINK2=         yes
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=		make
USE_X11=                yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
