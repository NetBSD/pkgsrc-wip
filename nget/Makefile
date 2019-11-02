# $NetBSD$

PKGNAME=		nget-${VER}
VER=			0.32
CATEGORIES=		news
MASTER_SITES=		https://gitlab.com/Rhialto/nget/-/archive/${GIT_TAG}/
EXTRACT_SUFX=		.tar.bz2
DISTNAME=		${GIT_TAG}-${PKGNAME}
GIT_TAG=		nget-${VER:S/./_/}
GIT_REV=		a2ff4e61dc5fb10ff9a8d1b36e4cfe7fe5a9bc3e
WRKSRC=			${WRKDIR}/nget-${GIT_TAG}-${GIT_REV}

MAINTAINER=		rhialto@NetBSD.org
HOMEPAGE=		https://gitlab.com/Rhialto/nget/
COMMENT=		Command line nntp file grabber
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake aclocal autoconf autoheader
USE_LANGUAGES=		c c++11

CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ARGS+=	--with-popt

EGDIR=			${PREFIX}/share/examples/nget
MESSAGE_SUBST+=		EGDIR=${EGDIR}

INSTALLATION_DIRS=	share/nget share/examples/nget
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	for f in COPYING Changelog FAQ README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/share/nget; done
	${INSTALL_DATA} ${WRKSRC}/.ngetrc ${DESTDIR}${EGDIR}/dot.ngetrc

.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
