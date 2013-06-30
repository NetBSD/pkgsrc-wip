# $NetBSD: Makefile,v 1.1 2013/06/30 22:58:21 othyro Exp $

DISTNAME=	smpeg2-2.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.libsdl.org/projects/smpeg/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/smpeg/
COMMENT=	Free MPEG1 video player library with sound support
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	smpeg-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../wip/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
