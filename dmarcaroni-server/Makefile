# $NetBSD$

DISTNAME=	dmarcaroni-server-0.1.0.0alpha2025.02.01
PKGNAME=	${DISTNAME}
CATEGORIES=	mail
# There are no official releases at the moment.
SITES.${DISTNAME}.tar.gz=	-https://git.disroot.org/lnrs/dmarcaroni-server/archive/bf7015d74d08d0e357f69575add7973922721c6f.tar.gz
WRKSRC=		${WRKDIR}/${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.disroot.org/lnrs/dmarcaroni-server
COMMENT=	Free and open source software to do DMARC monitoring
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	hpack

.include "../../graphics/hs-chart/buildlink3.mk"
.include "../../graphics/hs-chart-cairo/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../converters/hs-base64/buildlink3.mk"
.include "../../security/hs-blake2/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../geography/hs-country-codes/buildlink3.mk"
.include "../../www/hs-curl/buildlink3.mk"
.include "../../lang/dhall/buildlink3.mk"
.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-hxt-curl/buildlink3.mk"
.include "../../textproc/hs-hxt-relaxng/buildlink3.mk"
.include "../../net/hs-ip/buildlink3.mk"
.include "../../mail/hs-mbox/buildlink3.mk"
.include "../../net/hs-mime/buildlink3.mk"
OPTPARSE_APPLICATIVE_EXECUTABLES+=	\
	dmarcaroni-server
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../textproc/hs-stache/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-wide-word/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
