# $NetBSD: Makefile,v 1.1 2014/11/07 19:19:23 steven43126 Exp $

CHRUBY_VERSION= 0.3.8
PKGNAME=        chruby-${CHRUBY_VERSION}
DISTNAME=	v${CHRUBY_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/postmodern/chruby/archive/

MAINTAINER=	steve@freeagent.com
HOMEPAGE=	https://github.com/postmodern/chruby/archive/
COMMENT=	Changes the current Ruby
LICENSE=	mit

WRKSRC=		${WRKDIR}/chruby-0.3.8

NO_BUILD=       yes
REPLACE_BASH=   bin/chruby-exec
USE_TOOLS=      bash

.include "../../mk/bsd.pkg.mk"
