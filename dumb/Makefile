# $NetBSD: Makefile,v 1.12 2010/12/24 18:39:35 noud4 Exp $
#

DISTNAME=		dumb-0.9.3
PKGREVISION=		1
CATEGORIES=		audio devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		IT, XM, S3M and MOD player library
#LICENSE=		dumb-license

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=		gmake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dumb
	cd ${WRKSRC} && ${INSTALL_DATA} licence.txt readme.txt release.txt \
		${PREFIX}/share/doc/dumb
	cd ${WRKSRC}/docs && ${INSTALL_DATA} deprec.txt faq.txt howto.txt \
		ptr.txt dumb.txt fnptr.txt modplug.txt \
		${PREFIX}/share/doc/dumb

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
