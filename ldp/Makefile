
DISTNAME=	ldp
CATEGORIES=	net
MASTER_SITES=	http://kefren.NetBSD.ro/mpls/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://www.ietf.org/rfc/rfc3036.txt
COMMENT=	Label Distribution Protocol

BUILD_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldp ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
