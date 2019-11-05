# $NetBSD$

DISTNAME=	libmpq-0.4.2
CATEGORIES=	devel games
MASTER_SITES=	https://libmpq.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libmpq.org/download/
COMMENT=	Library to extract, create or manipulate mpq archives

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmpq.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 38
PY_PATCHPLIST=			yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
