# $NetBSD$

DISTNAME=	ardour-4.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ardour/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ardour.org/
COMMENT=	Digital Audio Workstation
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	bsdtar pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libs/gtkmm2ext/libgtkmm2ext.pc.in
PKGCONFIG_OVERRIDE+=	libs/midi++2/libmidi++.pc.in
PKGCONFIG_OVERRIDE+=	libs/pbd/libpbd.pc.in

# As of NetBSD-7.99.21 pkgsrc's checks cannot open file with rare unicode characters
CHECK_PORTABILITY_SKIP+=	libs/pbd/test/i18n_test/*.tst

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 35 # as of 4.4

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=   rm:-ldl
.endif

post-extract:
	${SED} -e 's!REVISION!${PKGVERSION_NOREV}!' \
		${FILESDIR}/revision.cc > ${WRKSRC}/libs/ardour/revision.cc

#./waf configure --strict --prefix=/usr --configdir=/etc --libjack=weak --ptformat --with-backends=jack,alsa,dummy
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--prefix=${PREFIX} \
			--configdir=${PKG_SYSCONFDIR} \
			--destdir=${DESTDIR} \
			--mandir=${PKGMANDIR} \
			--strict \
			--with-backends=dummy

# ./waf
# ./waf i18n
do-build:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install

.include "../../wip/vamp-plugin-sdk/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../wip/liblo/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
