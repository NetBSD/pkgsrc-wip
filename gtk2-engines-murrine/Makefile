# $NetBSD: Makefile,v 1.6 2014/01/31 11:47:42 lokivit Exp $

DISTNAME=	murrine-0.98.2
PKGNAME=	${DISTNAME:S/^/gtk2-engines-/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/murrine/0.98/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	loki.vt@gmail.com
HOMEPAGE=	http://www.cimitan.com/murrine/
COMMENT=	GTK2+ engine featuring a modern glassy look

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-animation

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
