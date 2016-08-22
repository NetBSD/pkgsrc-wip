# $NetBSD$

DISTNAME=	bk-7.3ce
PKGNAME=	${DISTNAME:S/bk/bitkeeper/}
CATEGORIES=	devel
MASTER_SITES=	http://www.bitkeeper.org/downloads/7.3ce/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitkeeper.org/
COMMENT=	Distributed Source Control System
LICENSE=	apache-2.0

USE_TOOLS+=	gmake bison lex groff perl bash gperf

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/libtomcrypt/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

pre-configure:
	perl -pe 's{BUILDLINK_DIR}{${BUILDLINK_DIR}}' \
		< files/conf.mk.local > ${WRKSRC}/src/conf.mk.local

do-build:
	${RUN} cd ${WRKSRC}/src && ${GMAKE}  # p

.include "../../mk/bsd.pkg.mk"
