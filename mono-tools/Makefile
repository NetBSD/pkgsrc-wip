# $NetBSD: Makefile,v 1.1.1.1 2008/03/19 12:15:44 koifren Exp $

DISTNAME=	mono-tools-${MONO_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/mono-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Tools for use with the Mono runtime

.include "../../wip/mono/Makefile.version"

PKGCONFIG_OVERRIDE+=	create-native-map/lib/pkgconfig/create-native-map.pc.in
PKGCONFIG_OVERRIDE+=	gendarme/framework/gendarme-framework.pc.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

MAKE_JOBS_SAFE=		no

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mono/buildlink3.mk"
.include "../../wip/monodoc/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
