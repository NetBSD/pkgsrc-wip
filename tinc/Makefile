# $NetBSD: Makefile,v 1.2 2004/02/23 17:59:51 minskim Exp $
#

DISTNAME=		tinc-1.0.1
CATEGORIES=		security net
MASTER_SITES=		http://tinc.nl.linux.org/packages/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://tinc.nl.linux.org/
COMMENT=		Virtual Private Network (VPN) daemon

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

INFO_FILES=		tinc.info

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
