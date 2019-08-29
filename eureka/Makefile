# $NetBSD$

DISTNAME=	eureka-124-source
PKGNAME=	${DISTNAME:S/-source//:S/-1/-1./}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-source

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
