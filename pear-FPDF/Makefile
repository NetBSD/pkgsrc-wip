# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $

DISTNAME=	FPDF-1.6.0
CATEGORIES=	print
MASTER_SITES+=	http://pearhub.org/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.pearhub.org/projects/FPDF
COMMENT=	Unofficial PEAR FPDF-library
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-pearhub-[0-9]*:../../wip/pear-channel-pearhub

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
