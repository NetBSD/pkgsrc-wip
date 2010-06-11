# $NetBSD: Makefile,v 1.2 2010/06/11 11:20:09 jihbed Exp $
#

DISTNAME=	ghemical-2.99.2
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/ghemical/download/release20090911/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.bioinformatics.org/ghemical/ghemical/
COMMENT=	Ghemical is a computational chemistry software package for GNOME
LICENSE=	gnu-gpl-v2


PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-gtk

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../wip/libghemical/buildlink3.mk"
.include "../../wip/liboglappth/buildlink3.mk"
.include "../../wip/openbabel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
