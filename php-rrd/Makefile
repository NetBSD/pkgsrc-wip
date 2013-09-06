# $NetBSD: Makefile,v 1.2 2013/09/06 10:56:11 yvs4sf Exp $

MODNAME=	rrd
PECL_VERSION=	1.1.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=	databases
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP extension provides bindings to the RRDtool C library
LICENSE=	php

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fix search path for rrdtool header files
SUBST_FILES.path=	config.m4
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
