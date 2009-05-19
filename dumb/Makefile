# $NetBSD: Makefile,v 1.10 2009/05/19 09:00:07 thomasklausner Exp $
#

DISTNAME=		dumb-0.9.3
CATEGORIES=		audio devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		IT, XM, S3M and MOD player library
LICENSE=		dumb-license

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
