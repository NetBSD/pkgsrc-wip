# $NetBSD: Makefile,v 1.2 2004/01/25 02:32:47 grantbeattie Exp $
#

DISTNAME=	mlview-0.6.0
CATEGORIES=	editors gnome2
MASTER_SITES=	http://savannah.gnu.org/download/mlview/tarballs/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.freespiders.org/projects/gmlview/
COMMENT=	XML editor for GNOME 2 environment

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/libcroco/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
