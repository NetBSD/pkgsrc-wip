# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:43 asau Exp $

DISTNAME=	re2-0.99
PKGNAME=	${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://code.google.com/p/re2/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://code.google.com/p/re2/
COMMENT=	RE2 is a fast, safe, thread-friendly regular expressions library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

HG_REPOSITORIES=	re2
HG_REPO.re2=		https://re2.googlecode.com/hg

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
