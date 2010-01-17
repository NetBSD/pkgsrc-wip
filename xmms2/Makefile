# $NetBSD: Makefile,v 1.21 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=	xmms2-0.2DrJekyll
PKGNAME=	xmms2-0.2rc10
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmms2.xmms.org/
COMMENT=	Audio player featuring a client-server model

HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes

PKGCONFIG_OVERRIDE+=	_build_/default/xmms2-client-cpp-glib.pc
PKGCONFIG_OVERRIDE+=	_build_/default/xmms2-plugin.pc
PKGCONFIG_OVERRIDE+=	_build_/default/xmms2-client.pc
PKGCONFIG_OVERRIDE+=	_build_/default/xmms2-client-glib.pc

do-configure:
	cd ${WRKSRC:Q} && ${PYTHONBIN} ./waf configure \
	--prefix=${PREFIX} --with-mandir=${PREFIX}/${PKGMANDIR}

do-build:
	cd ${WRKSRC:Q} && ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC:Q} && ${PYTHONBIN} ./waf install

.include "options.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
# just used for waf
BUILDLINK_DEPMETHOD.python=	build
.include "../../lang/python/application.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
