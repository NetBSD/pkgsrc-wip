# $NetBSD: Makefile,v 1.3 2015/07/12 00:35:40 thomasklausner Exp $

DISTNAME=	xtrkcad-source-5.1.2a
PKGNAME=	${DISTNAME:C/source-//}
CATEGORIES=	cad
MASTER_SITES=	http://sourceforge.net/projects/xtrkcad-fork/files/XTrackCad/Version%205.1.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xtrkcad.org/
COMMENT=	CAD program for designing model railroads
LICENSE=	apache-2.0

USE_TOOLS+=	gmake cmake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
