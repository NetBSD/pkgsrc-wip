# $NetBSD: Makefile,v 1.11 2010/01/18 09:38:34 thomasklausner Exp $
#

DISTNAME=		twinkle-1.4.2
PKGREVISION=		3
CATEGORIES=		audio chat net
MASTER_SITES=		http://www.xs4all.nl/~mfnboer/twinkle/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.twinklephone.com/
COMMENT=		Software Phone using the SIP protocol

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		have_lrelease=${QTDIR}/bin/lrelease
# for broken jpeg detection
CONFIGURE_ARGS+=	--with-extra-includes=${BUILDLINK_PREFIX.jpeg}/include
CPPFLAGS+=		-I${BUILDLINK_PREFIX.commoncpp2}/include/cc++2

SUBST_CLASSES+=		boost
SUBST_MESSAGE.boost=	Fix boost library name.
SUBST_STAGE.boost=	pre-configure
SUBST_FILES.boost=	configure
SUBST_SED.boost+=	-e 's,boost_regex-gcc,boost_regex-mt,'

.include "options.mk"

LDFLAGS+=		${BUILDLINK_LDADD.oss}

.include "../../mk/oss.buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
