# $NetBSD: Makefile,v 1.3 2004/02/17 02:55:18 blef Exp $
#

DISTNAME=		drwright-0.17
CATEGORIES=		x11
MASTER_SITES=		http://www.imendio.com/projects/drwright/download/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.imendio.com/projects/drwright/
COMMENT=		Computer break reminder

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_PERL5=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

GCONF2_SCHEMAS=		drwright.schemas

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
