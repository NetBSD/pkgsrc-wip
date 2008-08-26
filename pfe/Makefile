# $NetBSD: Makefile,v 1.4 2008/08/26 18:26:09 asau Exp $

DISTNAME=	pfe-0.33.69
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfe/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://pfe.sourceforge.net/
COMMENT=	Portable FORTH Environment

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-regs
USE_TOOLS+=	perl pkg-config

MAKE_JOBS_SAFE=	no
BUILD_TARGET=	all mans docs
INSTALL_TARGET=	install install-mans install-docs
TEST_TARGET=	tests

BUILD_DEPENDS=	xmlto-[0-9]*:../../textproc/xmlto	# documentation

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
