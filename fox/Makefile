# $NetBSD: Makefile,v 1.1.1.1 2004/09/07 22:36:14 cetrox Exp $
#

DISTNAME=		fox-1.2.9
CATEGORIES=		wip devel
MASTER_SITES=		http://www.fox-toolkit.org/ftp/

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://www.fox-toolkit.org/
COMMENT=		Fast and extensive C++ GUI toolkit

SUBST_CLASSES+=		art sshots
SUBST_MESSAGE.art=	"Fixing dir in doc/art/Makefile.in"
SUBST_FILES.art=	doc/art/Makefile.in
SUBST_SED.art=		-e \
	's|$(prefix)/@PACKAGE@/html/art|$(prefix)/share/@PACKAGE@/html/art|'
SUBST_STAGE.art=	post-extract
SUBST_MESSAGE.sshots=	"Fixing dir in doc/screenshots/Makefile.in"
SUBST_FILES.sshots=	doc/screenshots/Makefile.in
SUBST_SED.sshots=	-e \
	's|$(prefix)/@PACKAGE@/html/screenshots|$(prefix)/share/@PACKAGE@/html/screenshots|'
SUBST_STAGE.sshots=	post-extract

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
