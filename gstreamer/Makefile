# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 18:02:12 bmeurer Exp $

DISTNAME=		gstreamer-0.6.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gstreamer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		Framework for creating streaming media applications

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS=                gnome2-dirs>=1.0:../../misc/gnome2-dirs

AUTOCONF_REQD=		2.52
AUTOMAKE_REQD=		1.7
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer.pc.in

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--with-cachedir=/var/tmp/gstreamer

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I common/m4 && \
		libtoolize --copy --force && \
		${AUTOHEADER} && ${AUTOCONF} && \
		${AUTOMAKE} --add-missing --copy

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../lang/python22/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
