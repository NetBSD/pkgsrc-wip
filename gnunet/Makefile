# $NetBSD: Makefile,v 1.10 2004/11/08 17:27:39 tvierling Exp $
#

DISTNAME=	GNUnet-0.6.4a
PKGNAME=	${DISTNAME:S/GNU/gnu/}
CATEGORIES=	x11
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.ovmj.org/GNUnet/
COMMENT=	Framework for secure p2p networking

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
PLIST_SRC=		${WRKDIR}/PLIST.src
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=        --without-gtk
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
	${ECHO} '$f' >>${PLIST_SRC}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
