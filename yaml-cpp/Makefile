# $NetBSD: Makefile,v 1.4 2014/02/04 23:45:12 nros Exp $
#

DISTNAME=	yaml-cpp-0.5.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://yaml-cpp.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yaml-cpp/
COMMENT=	YAML 1.2 parser and emitter in C++
LICENSE=	mit

USE_CMAKE=		yes
USE_LANGUAGES+=		c c++

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
