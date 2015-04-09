# $NetBSD: Makefile,v 1.4 2015/04/09 02:10:30 krytarowski Exp $

DISTNAME=	mate-backgrounds-1.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Set of backgrounds packaged with the MATE desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		gmake intltool msgfmt
USE_PKGLOCALEDIR=	YES

BUILDLINK_DEPMETHOD.gettext=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
