# $NetBSD: Makefile,v 1.1 2014/08/08 11:55:56 chybz Exp $

DISTNAME=	nanomsgxx-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=achille-roussel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/achille-roussel/nanomsgxx/
COMMENT=	Nanomsg binding for C++11
LICENSE=	mit

USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	waf>=1.8.4:../../devel/waf

.include "../../wip/nanomsg/buildlink3.mk"
.include "../../devel/waf/waf.mk"
.include "../../mk/bsd.pkg.mk"
