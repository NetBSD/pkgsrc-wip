# $NetBSD: Makefile,v 1.1 2015/05/18 03:40:53 genolopolis Exp $

DISTNAME=	julia-0.3.8_79599ada44
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=JuliaLang/}
GITHUB_PROJECT=	julia
GITHUB_RELEASE=	v0.3.8
WRKSRC=		${WRKDIR}/julia

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://julialang.org/
COMMENT=	Julia is a high-level, high-performance dynamic programming language for technical computing
LICENSE=	mit

USE_TOOLS=	gmake
USE_LANGUAGES+=	c++
USE_LANGUAGES+=	c
USE_LANGUAGES+=	fortran
BUILD_DEPENDS+=	git-base>=1.0:../../devel/git-base

.include "../../mk/bsd.pkg.mk"
