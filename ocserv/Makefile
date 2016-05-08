# $NetBSD$

DISTNAME=	ocserv-0.11.2
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.infradead.org/pub/ocserv/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/ocserv/
COMMENT=	SSL VPN server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/autogen/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
# pkgsrc talloc pulls in python, use local copy
#.include "../../devel/talloc/buildlink3.mk"
# configure script fails to detect (Heimdal) GSSAPI
#.include "../../mk/krb5.buildlink3.mk"
# should support editline, but would need more patches
#.include "../../mk/readline.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
