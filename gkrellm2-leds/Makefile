# $NetBSD: Makefile,v 1.2 2003/12/31 12:42:35 cubidou Exp $
#

DISTNAME=	gkleds-0.8.1
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
CATEGORIES=	misc
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://heim.ifi.uio.no/~oyvinha/article.php?2.0.0
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
ALL_TARGET=	unix

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkleds.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
