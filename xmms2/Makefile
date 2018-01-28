# $NetBSD: Makefile,v 1.26 2014/08/11 23:10:14 thomasklausner Exp $

DISTNAME=	xmms2-0.8DrO_o
PKGNAME=	${DISTNAME:S/DrO_o//1}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmms2.org/wiki/Main_Page
COMMENT=	Audio player featuring a client-server model
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2 AND modified-bsd # possibly more?

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

HAS_CONFIGURE=		yes
USE_TOOLS+=		perl:build pkg-config
USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes

PKGCONFIG_OVERRIDE+=	xmms2.pc.in
EXTRA_INCLUDES=		${PREFIX}/include
WITHOUT_PLUGINS=	nms sc68 # XXX Someone, package these!

PLIST_SUBST+=		PERL5_SUB_INSTALLSITEARCHLIB=${PERL5_SUB_INSTALLARCHLIB:S|perl5/|perl5/site_perl/|1}

PY_PATCHPLIST=		yes

.include "options.mk"

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--destdir=${DESTDIR} --prefix=${PREFIX} \
			--conf-prefix="${EXTRA_INCLUDES}" \
			--with-default-output-plugin=oss \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--boost-includes=${BOOST_INCLUDES}
			# --without-plugins=${WITHOUT_PLUGINS} # space clobbered

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build --with-custom-version=pkgsrc

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install


.include "../../devel/SDL/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
