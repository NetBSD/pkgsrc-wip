# $NetBSD: Makefile,v 1.1 2007/05/27 06:55:15 bsadewitz Exp $
#

DISTNAME=	heliodor-0.2.1

.include "../../wip/beryl/Makefile.inc"

COMMENT=	Heliodor theme package for beryl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/beryl-core/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
