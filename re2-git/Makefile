# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:43 asau Exp $

DISTNAME=	re2-0.99
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://github.com/google/re2
COMMENT=	RE2 is a fast, safe, thread-friendly regular expressions library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

GIT_REPOSITORIES=	re2
GIT_REPO.re2=		git@github.com:google/re2.git

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
