# $NetBSD: Makefile,v 1.6 2004/01/25 02:12:39 grantbeattie Exp $
#

DISTNAME=	gkrellflynn-0.8
PKGNAME=	${DISTNAME:S/gkrell/gkrellm-/}
CATEGORIES=	systutils
MASTER_SITES=	http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://horus.comlab.uni-rostock.de/flynn/
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	gkrellm2
INSTALL_TARGET=	installgkrellm2

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
