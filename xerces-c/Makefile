# $NetBSD: Makefile,v 1.1.1.1 2010/11/03 21:32:59 zecrazytux Exp $
#

DISTNAME=	xerces-c-3.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.ox.ac.uk/sites/rsync.apache.org//xerces/c/3/sources/

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://xerces.apache.org/xerces-c/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0


PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xerces-c.pc.in

.include "../../mk/bsd.pkg.mk"
