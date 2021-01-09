# $NetBSD$

DISTNAME=	gtk-20191030
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	go-gtk
GITHUB_TAG=	af2e013261f57706ec683a61f85e8759a3faf6be
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mattn.github.com/go-gtk
COMMENT=	Go binding for GTK2
LICENSE=	2-clause-bsd

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=     github.com/mattn/${GITHUB_PROJECT}

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.6.0
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glu+=	glu>=3.4.2
.include "../../graphics/glu/buildlink3.mk"
.include "../../wip/go-pointer/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkglarea2+=	gtkglarea2>=2.0.1
.include "../../x11/gtkglarea2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.0.2<3
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
