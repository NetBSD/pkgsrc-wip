# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:14 asau Exp $
#

DISTNAME=	libopensync-plugin-python-0.22
PKGNAME=	${PYPKGPREFIX}-libopensync-plugin-0.22
CATEGORIES=	comms
#MASTER_SITES=	http://www.opensync.org/attachment/wiki/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opensync.org/attachment/wiki/download/
COMMENT=	Python support code for opensync plugins


GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

# XXX: needs python-enabled libopensync
.include "../../comms/libopensync/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
