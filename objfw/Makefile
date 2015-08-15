# $NetBSD: Makefile,v 1.5 2015/08/15 19:26:30 midar Exp $
#

DISTNAME=	objfw-0.8
MASTER_SITES=	https://webkeks.org/objfw/downloads/
EXTRACT_SUFX=	.tar.xz

CATEGORIES=	devel
COMMENT=	Portable, lightweight framework for the Objective-C language
LICENSE=	qpl-v1.0 OR gnu-gpl-v2 OR gnu-gpl-v3
HOMEPAGE=	https://webkeks.org/objfw/
MAINTAINER=	js@webkeks.org

GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
CONFIGURE_ARGS+=	--enable-static

.include "../../mk/bsd.pkg.mk"
