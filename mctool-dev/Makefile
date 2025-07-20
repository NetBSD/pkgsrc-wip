#	$NetBSD$

DISTNAME=	mctool-0.0a20250330.dev5
PKGNAME=	${DISTNAME}
CATEGORIES=	pkgtools
HG_REPO=	https://hg.mumble.net/campbell/pkgsrc-mctool
HG_TAG=		18e9df54aaeb6c1f8790f063565da09ec3063763

MAINTAINER=	riastradh@NetBSD.org
HOMEPAGE=	https://hg.mumble.net/campbell/pkgsrc-mctool
COMMENT=	High performance portable alternatives for pkgsrc/mk
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX:Q}/bin

TEST_TARGET=	check

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
