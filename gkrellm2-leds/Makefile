# $NetBSD: Makefile,v 1.3 2004/01/25 02:22:38 grantbeattie Exp $
#

DISTNAME=	gkleds-0.8.1
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
CATEGORIES=	misc
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://heim.ifi.uio.no/~oyvinha/article.php?2.0.0
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	unix

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkleds.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
