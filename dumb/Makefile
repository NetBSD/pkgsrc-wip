# $NetBSD: Makefile,v 1.2 2003/07/22 00:46:57 bencollver Exp $
#

DISTNAME=		dumb-0.9.2-fixed
PKGNAME=		dumb-0.9.2
WRKSRC=			${WRKDIR}/dumb
CATEGORIES=		audio devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		IT, XM, S3M and MOD player library

LICENSE=		dumb-license
USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dumb
	cd ${WRKSRC} && ${INSTALL_DATA} licence.txt readme.txt release.txt \
		${PREFIX}/share/doc/dumb
	cd ${WRKSRC}/docs && ${INSTALL_DATA} deprec.txt faq.txt howto.txt \
		ptr.txt dumb.txt fnptr.txt modplug.txt \
		${PREFIX}/share/doc/dumb

.include "../../wip/allegro/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
