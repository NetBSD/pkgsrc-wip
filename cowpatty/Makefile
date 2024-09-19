# $NetBSD: Makefile,v 1.2 2013/05/24 11:59:58 othyro Exp $
#

VERSION=	4.3
DISTNAME=	cowpatty-${VERSION}
CATEGORIES=	net security
MASTER_SITES=	http://www.willhackforsushi.com/code/cowpatty/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.willhackforsushi.com/Cowpatty.html
COMMENT=	Designed to audit the security of PSKs selected in WPA networks
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
INSTALL_ENV+=	PREFIX=${PREFIX}

.include "../../security/openssl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
