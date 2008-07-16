# $NetBSD: Makefile,v 1.3 2008/07/16 22:09:46 asau Exp $

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

BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc

BUILD_DEPENDS=	xmlto-[0-9]*:../../textproc/xmlto	# documentation

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
