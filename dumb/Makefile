# $NetBSD: Makefile,v 1.14 2015/08/18 20:35:47 yhardy Exp $
#

DISTNAME=		dumb-0.9.3
PKGREVISION=		1
CATEGORIES=		audio devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		IT, XM, S3M and MOD player library
#LICENSE=		dumb-license

USE_TOOLS+=		gmake pkg-config

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

INSTALLATION_DIRS+=	bin include lib share/doc/dumb

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} licence.txt readme.txt release.txt \
		${DESTDIR}${PREFIX}/share/doc/dumb
	cd ${WRKSRC}/docs && ${INSTALL_DATA} deprec.txt faq.txt howto.txt \
		ptr.txt dumb.txt fnptr.txt modplug.txt \
		${DESTDIR}${PREFIX}/share/doc/dumb

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
