# $NetBSD: Makefile,v 1.1.1.1 2005/05/25 02:09:04 jeremy-c-reed Exp $
#

DISTNAME=		gnome-pilot-2.0.12
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/2.0/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Palm Pilot synchronisation for GNOME

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_PERL5=		build
USE_TOOLS+=		gmake

#CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE}

# According to README, is a 'buildorder bug', and this is the recommended
# workaround.
#do-build:
#	(cd ${WRKSRC} && ${MAKE} -k && ${MAKE})

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
