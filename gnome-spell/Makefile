# $NetBSD: Makefile,v 1.1.1.1 2004/01/16 07:55:18 bseklecki Exp $

DISTNAME=	gnome-spell-1.0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-spell/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bitbucket@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Spell checking as you type like gtkspell

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
