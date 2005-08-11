# $NetBSD: Makefile,v 1.4 2005/08/11 10:08:23 absd Exp $
#

DISTNAME=		lingoteach-ui-0.3.9a
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lingoteach/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lingoteach.sourceforge.net/
COMMENT=		Language teaching program

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/liblingoteach/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
