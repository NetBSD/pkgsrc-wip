# $NetBSD: Makefile,v 1.21 2012/11/25 23:32:18 othyro Exp $
#

DISTNAME=	GNUnet-0.6.4a
PKGNAME=	${DISTNAME:S/GNU/gnu/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www2.cddc.vt.edu/gnu/ftp/gnu/gnunet/
# http://www.gnunet.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnunet.org/
COMMENT=	Framework for secure P2P networking

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
PLIST_SRC=		${WRKDIR}/PLIST.src
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
