# $NetBSD: Makefile,v 1.1.1.1 2007/12/02 22:02:04 ondratu Exp $
#

DISTNAME=	hal-info-20071030
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/hal
COMMENT=	Hal-info contains device information for HAL

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../wip/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
