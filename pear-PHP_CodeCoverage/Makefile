# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:09 noud4 Exp $
#

DISTNAME=	PHP_CodeCoverage-1.2.13
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pear.phpunit.de/
COMMENT=	Collection, processing, and rendering for PHP code coverage
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-File_Iterator>=1.3.0:../../wip/pear-File_Iterator
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_TokenStream>=1.1.3:../../wip/pear-PHP_TokenStream
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Text_Template>=1.1.1:../../wip/pear-Text_Template

USE_TOOLS+=	gtar

do-extract:
	cd ${WRKDIR} && gtar xfpz ${DISTDIR}/pear/${DISTNAME}${EXTRACT_SUFX}

.include "options.mk"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
