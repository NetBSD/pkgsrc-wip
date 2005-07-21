# $NetBSD: Makefile,v 1.3 2005/07/21 16:34:06 thomasklausner Exp $
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

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../wip/liblingoteach/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
