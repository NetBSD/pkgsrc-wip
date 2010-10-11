# $NetBSD: Makefile,v 1.1 2010/10/11 23:33:57 alnsn Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
