# $NetBSD: Makefile,v 1.2 2003/10/21 12:01:02 dillo Exp $
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

USE_BUILDLINK2=	yes

.include "../../wip/gtkglk/buildlink2.mk"
#.include "../../wip/glkterm/buildlink2.mk"
#.include "../../wip/xglk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
