# $NetBSD: Makefile,v 1.1.1.1 2003/10/20 13:24:28 dillo Exp $
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
USE_X11=	yes

.include "../../wip/gtkglk/buildlink2.mk"
#.include "../../wip/xglk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
