# $NetBSD: Makefile,v 1.3 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=	monotone-cvsimport-20080325
CATEGORIES=	devel scm
MASTER_SITES=	http://www.NetBSD.org/~bjs/distfiles/
EXTRACT_SUFX?=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Free distributed version control system

CONFLICTS=	monotone-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		yes
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake makeinfo msgfmt xgettext msgmerge pax
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-system-pcre

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6

CHECK_INTERPRETER_SKIP+=	share/monotone/contrib/*
CHECK_PORTABILITY_SKIP+=	debian/*

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/monotone
	cd ${WRKSRC} && rm -rf contrib/.deps && \
	    pax -rw -pp -pm contrib \
	    ${DESTDIR}${PREFIX}/share/monotone
	cd ${WRKSRC} && pax -rw -pp -pm figures/*.png \
	    ${DESTDIR}${PREFIX}/share/doc/monotone

BUILDLINK_API_DEPENDS.pcre+=	pcre>=7.6

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
