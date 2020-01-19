# $NetBSD: Makefile,v 1.3 2013/06/17 12:45:13 thomasklausner Exp $
#

DISTNAME=	weland-1.3-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	games editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weland/}
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	https://weland.sourceforge.net/
COMMENT=	Marathon game map editor
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/weland-1.3
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

.include "../../lang/mono2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
