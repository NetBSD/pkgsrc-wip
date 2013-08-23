# $NetBSD: Makefile,v 1.6 2013/08/23 01:09:34 szptvlfn Exp $

DISTNAME=	pandoc-1.11.1
CATEGORIES=	textproc

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Conversion between markup formats
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/pandoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man5/pandoc_markdown.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../devel/pcre/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-base64-bytestring/buildlink3.mk"
.include "../../wip/hs-blaze-html/buildlink3.mk"
.include "../../wip/hs-blaze-markup/buildlink3.mk"
.include "../../wip/hs-citeproc-hs/buildlink3.mk"
.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../wip/hs-digest/buildlink3.mk"
.include "../../wip/hs-highlighting-kate/buildlink3.mk"
.include "../../wip/hs-HTTP/buildlink3.mk"
.include "../../wip/hs-json/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-pandoc-types/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-pcre-light/buildlink3.mk"
.include "../../wip/hs-random//buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.include "../../wip/hs-tagsoup/buildlink3.mk"
.include "../../wip/hs-temporary/buildlink3.mk"
.include "../../wip/hs-texmath/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-xml/buildlink3.mk"
.include "../../wip/hs-zip-archive/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
