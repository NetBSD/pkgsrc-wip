# $NetBSD: Makefile,v 1.00 2015/12/03 01:40:00 coypu Exp $

VER=		0_pre20151022
DISTNAME=	pangoterm-0.${VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

HOMEPAGE=	http://www.leonerd.org.uk/code/pangoterm/
COMMENT=	GTK/Pango-based terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/pangoterm-0
USE_LANGUAGES=	c
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../wip/libvterm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
