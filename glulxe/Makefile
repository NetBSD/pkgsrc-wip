# $NetBSD: Makefile,v 1.3 2004/05/02 21:04:39 blef Exp $
#

DISTNAME=	glulxe-035
PKGNAME=	glulxe-0.3.5
WRKSRC=		${WRKDIR}/glulxe
CATEGORIES=	games
MASTER_SITES=	http://mirror.ifarchive.org/if-archive/programming/glulx/interpreters/glulxe/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.eblong.com/zarf/glulx/index.html
COMMENT=	Interpreter for Glulx text adventures

USE_BUILDLINK3=	yes

.include "../../wip/gtkglk/buildlink3.mk"
#.include "../../wip/glkterm/buildlink3.mk"
#.include "../../wip/xglk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
