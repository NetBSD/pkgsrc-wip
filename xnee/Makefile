# $NetBSD: Makefile,v 1.1 2014/08/09 16:44:46 thomasklausner Exp $

DISTNAME=	xnee-3.19
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU:=xnee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/xnee/
COMMENT=	Record, replay, and distribute user actions under X11
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
