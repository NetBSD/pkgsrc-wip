# $NetBSD: Makefile,v 1.1 2015/01/22 22:44:59 schnoebe Exp $

PKGNAME=	${DISTNAME:C/source-//}
DISTNAME=	xtrkcad-source-4.2.0-beta1
CATEGORIES=	cad
MASTER_SITES=	http://sourceforge.net/projects/xtrkcad-fork/files/XTrackCad/Version%204.2.0-beta1/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.xtrkcad.org/
COMMENT=	CAD program for designing model railroads
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake cmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

USE_CMAKE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
