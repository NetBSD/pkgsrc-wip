# $NetBSD: Makefile,v 1.3 2004/05/14 00:41:31 blef Exp $

DISTNAME=		map-browse-1.1
WRKSRC=                 ${WRKDIR}/map-browse
CATEGORIES=		graphics
MASTER_SITES=		http://www.olib.org/~rkr/mud/software/map-browse/

# Can be set to following line when imported into pkgsrc;
# rkr does not want to maintain it in pkgsrc-wip.
#MAINTAINER=		rkr@olib.org
MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.olib.org/~rkr/mud/software/map-browse/
COMMENT=		GLUT-based 3D data graph (vertices, edges) viewer

USE_BUILDLINK3=		yes

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
