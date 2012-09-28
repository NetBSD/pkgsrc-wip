# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:47 asau Exp $
#

VER=	1.2.0
PKGNAME=    fastbit-${VER}
DISTNAME=	fastbit-ibis${VER}
CATEGORIES=	databases
MASTER_SITES=	https://codeforge.lbl.gov/frs/download.php/208/

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://sdm.lbl.gov/fastbit/
COMMENT=	Efficient Compressed Bitmap Index Technology
LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
