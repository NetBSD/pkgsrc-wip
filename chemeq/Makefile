# $NetBSD: Makefile,v 1.1 2014/07/15 13:38:02 jihbed Exp $

DISTNAME=	chemeq_2.12.orig
PKGNAME=	chemeq-2.12
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/c/chemeq/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://savannah.nongnu.org/projects/chemeq/
COMMENT=	Chemical Equation Parser and Renderer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/chemeq-2.12.orig

USE_TOOLS+=	bison gmake perl
USE_LANGUAGES=	c c++

REPLACE_PERL+=	tests/chemreport.pl

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
