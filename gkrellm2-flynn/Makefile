# $NetBSD: Makefile,v 1.3 2003/12/31 10:47:59 cubidou Exp $
#

DISTNAME=	gkrellflynn-0.8
PKGNAME=	${DISTNAME:S/gkrellm/gkrellm-/}
CATEGORIES=	systutils
MASTER_SITES=	http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://horus.comlab.uni-rostock.de/flynn/
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
ALL_TARGET=	gkrellm2
INSTALL_TARGET=	installgkrellm2

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
