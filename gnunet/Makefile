# $NetBSD$
#

# This is a pre-release, with 0.11 release coming soon. pre66 being best for
# testing the package. This prerelease will fail to build.
DISTNAME=	gnunet-0.11.0pre66
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://gnunet.org/
COMMENT=	Framework for secure P2P networking
LICENSE=	gnu-agpl-v3

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
PLIST_SRC=		${WRKDIR}/PLIST.src
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-nss=${BUILDLINK_PREFIX.nss}/lib

post-patch:
	cd ${WRKSRC} && for f in contrib/gnunet.* src/include/gnunet_util.h doc/man/*.?; do \
		${ECHO} $$f && \
		${SED} -e 's,/etc/gnunet\.conf,${PKG_SYSCONFDIR}/gnunet.conf,g' $$f >$$f.tmp && \
		${MV} -f $$f.tmp $$f; \
	done
	${RM} -f ${WRKSRC}/src/util/generate_*_conf.c

post-build:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
.for f in ${GNUNET_PLIST_ADD}
	${ECHO} ${f:Q} >>${PLIST_SRC}
.endfor

.include "../../audio/libopus/buildlink3.mk"
.include "../../databases/postgresql96-client/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
