# $NetBSD: Makefile,v 1.2 2003/10/18 13:10:56 cjep Exp $
#

DISTNAME=		liferea-0.3.3
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Liferea is a simple FeedReader clone for reading RSS/RDF feeds

USE_BUILDLINK2=         yes
GNU_CONFIGURE=          yes
USE_GMAKE=              yes
USE_X11=                yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
