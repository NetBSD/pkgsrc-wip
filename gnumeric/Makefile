# $NetBSD: Makefile,v 1.5 2004/01/25 02:22:58 grantbeattie Exp $
#

DISTNAME=	gnumeric-1.2.2
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/gnumeric/
COMMENT=	Spreadsheet program from the GNOME project

#DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
# for Python support a shared libpython is required but not provided yet
#BUILD_DEPENDS+=		python>=2.0:../../lang/python
BUILDLINK_DEPENDS.freetype2=	freetype2>=2.1.4

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
LIBS+=      		-lunicode

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS=		gnumeric-dialogs.schemas
GCONF2_SCHEMAS+=	gnumeric-general.schemas
GCONF2_SCHEMAS+=	gnumeric-plugins.schemas

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
