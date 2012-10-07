# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:07 asau Exp $
#

DISTNAME=	weland-1.3-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weland/}
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://weland.sourceforge.net/
COMMENT=	Marathon game map editor
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/weland-1.3
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
