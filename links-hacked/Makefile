# $NetBSD: Makefile,v 1.2 2003/07/31 01:18:25 xtraeme Exp $
#

DISTNAME=	links-hacked-${VER}
CATEGORIES=	www
MASTER_SITES=	http://xray.sai.msu.ru/~karpov/links-hacked/downloads/
EXTRACT_SUFX=	.tgz
DISTFILES+=     ${DISTNAME}${EXTRACT_SUFX} links-fonts-new${EXTRACT_SUFX}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://xray.sai.msu.ru/~karpov/links-hacked/
COMMENT=        Enhanced version of Links with tabs and more

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

VER=			030709

CONFLICTS+=	links-[0-9]* links-gui-[0-9]* elinks-[0-9]*

LDFLAGS+=		-lpng
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-javascript
CONFIGURE_ARGS+=	--enable-form-saving
CONFIGURE_ARGS+=	--enable-graphics

post-extract:
	@${MV} ${WRKDIR}/font ${WRKSRC}

pre-configure:
	@cd ${WRKSRC};                                           \
	${ACLOCAL};                                             \
	${AUTOHEADER};                                          \
	${AUTOMAKE} -a --foreign -i;                            \
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
