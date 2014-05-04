# $NetBSD: Makefile,v 1.1 2014/05/04 03:15:21 othyro Exp $

DISTNAME=	libarchive-3.1.2
CATEGORIES=	archivers
MASTER_SITES=	http://www.libarchive.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libarchive.org/
COMMENT=	Multi-format archive and compression library
LICENSE=	2-clause-bsd

CONFLICTS+=	bsdtar-[0-9]*
CONFLICTS+=	libarchive<=3.1.2

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=			pkgmandir
SUBST_FILES.pkgmandir=		CMakeLists.txt
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR path.
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|g"
SUBST_STAGE.pkgmandir=		pre-configure

.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.libxml2+=	libxml2>=2.9.1
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.bzip2+=	bzip2>=1.0.5
.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
