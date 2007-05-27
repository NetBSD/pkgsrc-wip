# $NetBSD: Makefile,v 1.14 2007/05/27 17:59:12 tnn2 Exp $
#

DISTNAME=	xmms2-0.2DrJekyll
PKGNAME=	xmms2-0.2rc8
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmms2.xmms.org/
COMMENT=	Audio player featuring a client-server model

BUILD_DEPENDS+=		python24>=2.4.0:../../lang/python24

HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes

do-configure:
	cd ${WRKSRC:Q} && ${PREFIX}/bin/python2.4 ./waf configure \
	--prefix=${PREFIX} --with-mandir=${PREFIX}/man

do-build:
	cd ${WRKSRC:Q} && ${PREFIX}/bin/python2.4 ./waf build

do-install:
	cd ${WRKSRC:Q} && ${PREFIX}/bin/python2.4 ./waf install


.include "options.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
