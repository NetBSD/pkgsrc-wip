# $NetBSD: Makefile,v 1.3 2006/05/31 19:15:51 ghen Exp $
#

DISTNAME=		opal-v2_2_1-src
PKGNAME=		opal-2.2.1
CATEGORIES=		net comms
MASTER_SITES+=		http://www.voxgratia.org/releases/
EXTRACT_SUFX=		-tar.gz

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://sourceforge.net/projects/openh323/
COMMENT=		Open Phone Abstraction Library

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src$//:S/-/_/}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_FILES.pwlib=	share/pwlib/make/*.mak

post-wrapper:
	${LN} -s ../../share ${BUILDLINK_DIR}/include/ptlib/
	${LN} -s ../../share/pwlib/make ${BUILDLINK_DIR}/include/ptlib/

CONFIGURE_ENV+=		PWLIBDIR=${BUILDLINK_DIR}/include/ptlib

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake


.include "../../wip/pwlib/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
