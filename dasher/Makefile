# $NetBSD: Makefile,v 1.2 2004/02/08 02:37:50 mpasternak Exp $
#

DISTNAME=		dasher-3.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.inference.phy.cam.ac.uk/dasher/download/linux/source/3.2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.inference.phy.cam.ac.uk/dasher/
COMMENT=		Easy typing without using keyboard

DEPENDS+=		xdg-dirs>=1.0:../../misc/xdg-dirs

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	# defined
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../textproc/expat/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
