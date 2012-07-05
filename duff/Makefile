# $NetBSD: Makefile,v 1.3 2012/07/05 14:50:18 othyro Exp $
#

DISTNAME=	duff-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://duff.sourceforge.net/
COMMENT=	Quickly finds duplicates in a given set of files
LICENSE=	png-license

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
