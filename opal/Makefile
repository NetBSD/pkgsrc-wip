# $NetBSD: Makefile,v 1.6 2007/08/05 06:34:18 othyro Exp $
#

DISTNAME=		opal-v2_2_4-src
PKGNAME=		opal-2.2.4
CATEGORIES=		net comms
MASTER_SITES+=		http://www.voxgratia.org/releases/
EXTRACT_SUFX=		-tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/openh323/
COMMENT=		Open Phone Abstraction Library

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src$//:S/-/_/}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_FILES.pwlib=	share/pwlib/make/*.mak

post-wrapper:
	${LN} -s ../../share ${BUILDLINK_DIR}/include/ptlib/
	${LN} -s ../../share/pwlib/make ${BUILDLINK_DIR}/include/ptlib/

CONFIGURE_ENV+=		PWLIBDIR=${BUILDLINK_DIR}/include/ptlib

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake


.include "../../devel/pwlib/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
