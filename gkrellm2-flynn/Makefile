# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 15:40:05 cubidou Exp $
#

DISTNAME=	gkrellflynn-0.6
PKGNAME=	gkrellm-flynn-0.6
CATEGORIES=	systutils
MASTER_SITES=	http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://horus.comlab.uni-rostock.de/flynn/
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
ALL_TARGET=	gkrellm2
INSTALL_TARGET=	installgkrellm2

.include "../../sysutils/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
