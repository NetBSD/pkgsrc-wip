# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 23:00:09 xtraeme Exp $
#

DISTNAME=		tinc-1.0.1
CATEGORIES=		security net
MASTER_SITES=		http://tinc.nl.linux.org/packages/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://tinc.nl.linux.org/
COMMENT=		Virtual Private Network (VPN) daemon

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

INFO_FILES=		tinc.info

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
