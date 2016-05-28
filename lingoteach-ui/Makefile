# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		lingoteach-ui-0.3.9a
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lingoteach/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
