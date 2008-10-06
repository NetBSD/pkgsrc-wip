# $NetBSD: Makefile,v 1.6 2008/10/06 11:01:34 absd Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/
EXTRACT_SUFX=	.tar.bz2

KTORRENT_VER=	3.1.3

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		awk msgfmt pkg-config perl

.include "../../mk/bsd.prefs.mk"

# As of at least NetBSD-4.0 the shipped gettext cannot handle the .po files,
# so we strip out usage of the newer features (context and fuzzy matches)
.if (${OPSYS} == "NetBSD")
post-patch:
	for f in ${WRKSRC}/po/*/ktorrent.po ; do \
	    mv $$f $$f.original ; \
	    ${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../wip/kde4/kde4.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
