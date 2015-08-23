# $NetBSD: Makefile,v 1.4 2015/08/23 17:14:18 midar Exp $

DISTNAME=	objfw-0.0
CATEGORIES=	devel

COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3
HOMEPAGE=	https://webkeks.org/objfw/
MAINTAINER=	js@webkeks.org

GIT_REPOSITORIES=	objfw
GIT_REPO.objfw=		https://webkeks.org/git/objfw.git

WRKSRC=			${WRKDIR}/objfw
USE_TOOLS=		aclocal automake
GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
