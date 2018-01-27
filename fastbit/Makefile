# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:27 thomasklausner Exp $
#

VER=		1.2.0
PKGNAME=	fastbit-${VER}
DISTNAME=	fastbit-ibis${VER}
CATEGORIES=	databases
MASTER_SITES=	https://codeforge.lbl.gov/frs/download.php/208/

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://sdm.lbl.gov/fastbit/
COMMENT=	Efficient Compressed Bitmap Index Technology
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
