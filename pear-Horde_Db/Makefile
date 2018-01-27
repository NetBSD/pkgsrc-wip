# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:53 asau Exp $
#

DISTNAME=	Horde_Db-1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/
EXTRACT_USING=	bsdtar

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Database abstraction for horde
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Date-[0-9]*:../../wip/pear-Horde_Date
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Support-[0-9]*:../../wip/pear-Horde_Support

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	bin/horde-db-migrate-component

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
