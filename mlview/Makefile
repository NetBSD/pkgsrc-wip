# $NetBSD: Makefile,v 1.4 2004/02/24 17:11:57 jmmv Exp $
#

DISTNAME=	mlview-0.6.0
CATEGORIES=	editors gnome2
MASTER_SITES=	http://savannah.gnu.org/download/mlview/tarballs/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.freespiders.org/projects/gmlview/
COMMENT=	XML editor for GNOME 2 environment

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
