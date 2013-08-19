# $NetBSD: Makefile,v 1.1 2013/08/19 19:30:55 airhead Exp $
#

DISTNAME=	yaml-cpp-0.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://yaml-cpp.googlecode.com/files/

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://code.google.com/p/yaml-cpp/
COMMENT=	YAML 1.2 parser and emitter in C++
LICENSE=	mit

USE_LIBTOOL=		yes
USE_CMAKE=		yes
USE_LANGUAGES+=		c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
