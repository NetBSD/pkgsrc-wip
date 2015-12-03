# $NetBSD$

DISTNAME=	ardour-4.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ardour/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ardour.org/
COMMENT=	Digital Audio Workstation
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	bsdtar pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libs/gtkmm2ext/libgtkmm2ext.pc.in
PKGCONFIG_OVERRIDE+=	libs/midi++2/libmidi++.pc.in
PKGCONFIG_OVERRIDE+=	libs/pbd/libpbd.pc.in

.include "../../mk/bsd.pkg.mk"
