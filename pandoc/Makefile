# $NetBSD: Makefile,v 1.34 2015/01/08 11:53:16 szptvlfn Exp $

DISTNAME=	pandoc-1.12.3.3
PKGNAME=	${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Conversion between markup formats
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${INSTALL_MAN} ${DESTDIR}${PREFIX}/share/man/man1/pandoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${DESTDIR}${PREFIX}/share/man/man5/pandoc_markdown.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	rm -rf ${DESTDIR}${PREFIX}/share/man

BUILD_DEPENDS=	alex-[0-9]*:../../devel/alex
BUILD_DEPENDS+=	happy-[0-9]*:../../devel/happy

.include "../../wip/mk/haskell.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-highlighting-kate/buildlink3.mk"
.include "../../wip/hs-hslua/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-texmath/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../wip/hs-yaml/buildlink3.mk"
.include "../../wip/hs-zip-archive/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
