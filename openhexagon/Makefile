# $NetBSD$

DISTNAME=	SSVOpenHexagon
PKGNAME=	openhexagon-${GITHUB_TAG}
CATEGORIES=	games

GITHUB_PROJECT=	SSVOpenHexagon
GITHUB_TAG=	2.0-preview
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}

DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVOpenHexagon
COMMENT=	C++14 FOSS clone of Super Hexagon
LICENSE=	afl

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake
USE_CMAKE=	yes

# Workaround required because a full recursive clone fails with git-package.mk
# and all dependencies are only handled via git submodules.
pre-configure:
	cd ${WRKSRC} && \
		git config --file .gitmodules --get-regexp url |\
			sed 's/submodule.\(.*\).url/\1/g' |\
			awk '{ system("GIT_SSL_NO_VERIFY=true git clone --recursive "$$2" "$$1) }'

.include "../../devel/sparsehash/buildlink3.mk"
.include "../../wip/sfml+/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
