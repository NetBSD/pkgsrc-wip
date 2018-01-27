# $NetBSD: Makefile,v 1.2 2014/11/08 14:02:18 steven43126 Exp $

DISTNAME=	chruby-0.3.8
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/postmodern/chruby/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	steve@freeagent.com
HOMEPAGE=	https://github.com/postmodern/chruby/
COMMENT=	CLI tool which allows you to manage/use multiple Ruby environments
LICENSE=	mit

NO_BUILD=	yes
REPLACE_BASH=	bin/chruby-exec
USE_TOOLS+=	bash:run

.include "../../mk/bsd.pkg.mk"
