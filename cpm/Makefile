# $NetBSD: Makefile,v 1.1.1.1 2008/10/31 20:41:22 shattered Exp $
#

DISTNAME=	cpm
PKGNAME=	cpm-0.22rc1
CATEGORIES=	security
MASTER_SITES=	http://www.harry-b.de/downloads/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.harry-b.de/dokuwiki/doku.php?id=harry:cpm
COMMENT=	Console Password Manager

WRKSRC=			${WRKDIR}/cpm-0.22beta
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-crack-dict=${PREFIX}/libdata/pw_dict
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	perl gmake

.include "../../devel/cdk/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../wip/dotconf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
