# $NetBSD: Makefile,v 1.1.1.1 2011/08/04 10:39:02 ryo-on Exp $
#

DISTNAME=	js185-1.0.0
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA:=js/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en/SpiderMonkey
COMMENT=	Standalone JavaScript implementation in C
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/js-1.8.5/js/src
USE_TOOLS+=	pkg-config perl:build gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=	NO

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-system-nspr

PKGCONFIG_OVERRIDE+=	ctypes/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	mozjs185.pc.in

.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
