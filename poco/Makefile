# $NetBSD: Makefile,v 1.2 2009/11/03 00:19:28 schnoebe Exp $
#

DISTNAME=	poco-1.3.5-all
PKGNAME=	poco-1.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pocoproject.org/
COMMENT=	POCO C++ libraries
# LICENSE=	boost

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX} --omit=Data

.if !empty(OPSYS:M*BSD)
CONFIGURE_ARGS+=	--config=FreeBSD
.endif

.if ${OPSYS} == "NetBSD"
# NetBSD doesn't have fenv.h. We should add one.
CONFIGURE_ARGS+=	--no-fpenvironment
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
