# $NetBSD: Makefile,v 1.3 2004/01/16 09:25:49 minskim Exp $

DISTNAME=	gnome-spell-1.0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-spell/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bitbucket@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Spell checking as you type like gtkspell

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../net/ORBit2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
