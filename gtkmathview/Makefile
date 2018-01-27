# $NetBSD: Makefile,v 1.1 2014/12/26 21:16:29 nros Exp $

DISTNAME=	gtkmathview-0.8.0
CATEGORIES=	math
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://helm.cs.unibo.it/mml-widget/
COMMENT=	MathML renderer with gtk widgets
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gtkmathview-custom-reader.pc.in
PKGCONFIG_OVERRIDE+=	gtkmathview-gmetadom.pc.in
PKGCONFIG_OVERRIDE+=	gtkmathview-libxml2-reader.pc.in
PKGCONFIG_OVERRIDE+=	gtkmathview-libxml2.pc.in
PKGCONFIG_OVERRIDE+=	mathview-backend-gtk.pc.in
PKGCONFIG_OVERRIDE+=	mathview-backend-ps.pc.in
PKGCONFIG_OVERRIDE+=	mathview-backend-svg.pc.in
PKGCONFIG_OVERRIDE+=	mathview-core.pc.in
PKGCONFIG_OVERRIDE+=	mathview-frontend-custom-reader.pc.in
PKGCONFIG_OVERRIDE+=	mathview-frontend-gmetadom.pc.in
PKGCONFIG_OVERRIDE+=	mathview-frontend-libxml2-reader.pc.in
PKGCONFIG_OVERRIDE+=	mathview-frontend-libxml2.pc.in

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/${PKGBASE}.conf.xml \
			${PKG_SYSCONFDIR}/${PKGBASE}.conf.xml
PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../devel/pangox-compat/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/gmetadom/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
