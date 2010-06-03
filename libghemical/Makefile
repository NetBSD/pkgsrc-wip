# $NetBSD: Makefile,v 1.1.1.1 2010/06/03 13:14:55 jihbed Exp $
#

DISTNAME=	libghemical-2.99.1
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/ghemical/download/release20090911/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.bioinformatics.org/ghemical/libghemical/index.html
COMMENT=	Molecular modelling library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libghemical.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.libghemical
PKG_SUPPORTED_OPTIONS=	mopac7 mpqc


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmopac7)
CONFIGURE_ARGS+=		--enable-mopac7
.endif

.if !empty(PKG_OPTIONS:Mmpqc)
CONFIGURE_ARGS+=		enable-mpqc
.endif

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
