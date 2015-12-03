# $NetBSD: Makefile,v 1.00 2015/12/03 01:40:00 coypu Exp $

DISTNAME=	pangoterm-0.${VER}
PKGNAME=	pangoterm
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

HOMEPAGE=	http://www.leonerd.org.uk/code/pangoterm/
COMMENT=	GTK/Pango-based terminal
LICENSE=	mit

VER=		0_pre20151022

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
.include "../../wip/libvterm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
