# $NetBSD: Makefile,v 1.1 2015/01/01 08:29:23 obache Exp $

DISTNAME=	mate-calc-1.8.0
CATEGORIES=	math
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Calculator application for MATE desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
